#include "mfqs_table.h"
#include <fstream>
#include <sstream>
#include <cmath>

void MFQS_Table::print_attributes()
{
    cout << endl << "Num Queues:     " << num_queues << endl;
    cout << "Num Processes:  " << num_procs << endl;
    cout << "Aging interval: " << aging_interval << endl;
}

bool MFQS_Table::all_empty(vector<priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Proc::MFQS_Compare> > &queues)
{
    for(int i = 0; i < num_queues; i++)
    {
    
        if(!queues[i].empty())
        {
            return false;
        }
    }
    return true;
}

void MFQS_Table::demote_process(MFQS_Proc &proc, vector<priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Proc::MFQS_Compare> > &queues,int idx)
{
    if (num_queues == 1)
        queues[idx].push(proc);
    else if (idx < num_queues-1)
        queues[idx+1].push(proc);
}

void MFQS_Table::promote_process(MFQS_Proc &proc, vector<priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Proc::MFQS_Compare> > &queues,int idx)
{
    queues[idx-1].push(proc);
}

void MFQS_Table::run()
{
    //vector<priority_queue> queues;
    vector<priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Proc::MFQS_Compare> > queues(num_queues); 

    cout << "Enter the desired time quantum: " << endl;
    int base_quantum;
    cin >> base_quantum;
        
    cout << "Enter the desired aging interval: " << endl;
    cin >> aging_interval;
    // Get info needed for processes
    cout << endl << "1) Use a file" << endl;
    cout << "2) Enter information manually" << endl;
    cout << endl << "Choose whether to use a file or to manually enter your information: ";

    int input;
    cin >> input;
    
    int pid, burst, arrival, priority, queue_level, deadline, io;
    //priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Proc::MFQS_Compare> queue;
    
    
    if(input == 1)
    {
        cout << "Please enter the file path: ";
        string path;
        cin >> path;
        ifstream file;
        file.open(path);
        string process;
        string str;
        vector<MFQS_Proc> processes;

        getline(file,process);
        while(getline(file,process)){
            istringstream ss(process);

            ss >> pid >> burst >> arrival >> priority >> deadline >> io;
            if(pid < 0 || burst < 0 || arrival < 0 || priority < 0 || deadline < 0 || io < 0)
            {
                continue;
            }
            else
            {
                MFQS_Proc proc(pid, burst, arrival, priority, 0);
                queues[0].push(proc);
            }
        }

    }
    else if(input == 2)
    {

        
        cout << "Enter the number of processes you wish to enter: " << endl;
        cin >> num_procs;
        
        for(int i = 0; i < num_procs; i++)
        {
            cout << "************* Process " << i << " **************" << endl;
            cout << endl << "Enter PID: ";
            cin >> pid;
            cout << "Enter burst: ";
            cin >> burst;
            cout << "Enter arrival: ";
            cin >> arrival;
            cout << "Enter priority: ";
            cin >> priority;

            if(pid < 0 || burst < 0 || arrival < 0 || priority < 0)
            {
                cout << "Invalid proc. Pid #" << pid << endl;
                continue;
            }
            else
            {
                cout << "Pushing Proc" << endl;
                MFQS_Proc proc(pid, burst, arrival, priority, 0);
                queues[0].push(proc);
            }
        }

    }
    else
    {
        cout << "WROOOOONG" << endl;
        exit(0);
        // TODO send user back to start of init
    }

    int clock = 0;
    int max =  500;


    while(!all_empty(queues))
    {
        /*cout << "Inside While Clock: " << clock << endl;
        for(int i = 2; i < num_queues-1; i++){
            if(!queues[i].empty()){
                MFQS_Proc k = queues[i].top();
                cout << "Demo Time: " << k.demotion_time << " Age: " << k.age << endl;
                if(k.get_demotion_time() + k.get_age() > clock){
                    promote_process(k,queues,i);
                    cout << "PROMOTING!!!" << endl;
                }
                else{
                    k.age += aging_interval;
                }
            }
            else
                continue;
        }*/
        int time_quantum = base_quantum;
        for(int i = 0; i < num_queues; i++) 
        {
            if (i > 0)
                time_quantum = time_quantum * 2;
            MFQS_Proc p;
            if(!queues[i].empty()){
                p = queues[i].top();
            }
            else{ continue; }
             
            if(p.get_arrival() <= clock)
            {
                int burst = p.get_burst();
                int pid = p.get_pid();

                // Burst shorter than time quantum - move clock forward value of burst & remove proc
                if(burst - time_quantum < 0 && i != num_queues-1)
                {
                    #ifdef DEBUG
                      cout << "Q" << i+1 << ": Proc #" << pid << " finished in less than time quantum" << endl;
                      cout << "\t" << "Starting time: " << clock << endl;
                      cout << "\t" << "Ending time: " << clock+burst << endl;
                    #endif
                    clock = clock + burst;
                    queues[i].pop();
                    break;
                }

                // Burst longer than time quantum - needs to be demoted
                else if(burst - time_quantum > 0 && i != num_queues-1)
                {
                    #ifdef DEBUG
                      cout << "Q" << i+1 << ": Proc #" << pid << " did not complete process. Demoting" << endl;
                      cout << "\t" << "Starting time: " << clock << endl;
                      cout << "\t" << "Ending time: " << clock+time_quantum << endl;
                    #endif
                    clock = clock+time_quantum;
                    queues[i].pop();
                    p.decrease_burst(time_quantum);
                    if (i > 1) {
                        p.demotion_time = clock;
                    }
                    demote_process(p, queues, i);
                    break;
                }
                else if (burst - time_quantum > 0 && i == num_queues -1)
                {
                    #ifdef DEBUG
                      cout << "Q" << i+1 << ": Proc #" << pid << " in last queue finished remainder of burst: " << burst << endl;
                      cout << "\t" << "Starting time: " << clock << endl;
                      cout << "\t" << "Ending time: " << clock+burst << endl;
                    #endif
                    clock = clock + burst;
                    queues[i].pop();
                    break;
                }

                // Burst equal to time quantum - remove proc & move clock forward value of time quantum
                else
                {
                    #ifdef DEBUG
                      cout << "Q" << i+1 << ": Proc #" << pid << " completed in the allotted space" << endl;
                      cout << "\t" << "Starting time: " << clock << endl;
                      cout << "\t" << "Ending time: " << clock+time_quantum << endl;
                    #endif
                    clock = clock + time_quantum;
                    queues[i].pop();
                    break;
                }
            }
            else
            {
                // If no event happens move clock forward one tick
                clock++;
                cout << "No event happened. Clock now at " << clock << endl;
            }
        }
    }
    exit(0);
}

