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
  if(idx > 2 && idx < num_queues-1){
    cout << "=== PROMOTING #" << proc.get_pid() << " From Q" << idx << " To Q" << idx-1 << " Demotion Time: " << proc.get_demotion_time() << " Current Age: " << proc.get_age() << endl;
    queues[idx-1].push(proc);
  }
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

    int input = from_file();
    
    int pid, burst, arrival, priority, deadline, io;
    //priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Proc::MFQS_Compare> queue;
    
    int total_processes = 0;
    int total_waiting = 0;
    int total_turnaround = 0;
    
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
        total_processes = queues[0].size();

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

    while(!all_empty(queues))
    {
        int time_quantum = base_quantum;
        for(int i = 0; i < num_queues; i++) 
        {
            if (i > 0)
                time_quantum = time_quantum * 2;
            MFQS_Proc p;
            if(!queues[i].empty()){
                p = queues[i].top();
                /* Promoting Code, so close */
                /* if (i > 2 && i < num_queues-1){ */
                /*   queues[i].pop(); */
                /*   if(p.get_demotion_time() + p.get_age() > clock){ */
                /*       promote_process(p,queues,i); */
                /*       /1* cout << "PROMOTING AGE: " << p.get_age() << " + DEMO: " << p.get_demotion_time() << " = " << p.get_age()+p.get_demotion_time() << " Clock: " << clock << endl; *1/ */
                /*       break; */
                /*   } */
                /*   else{ */
                /*       p.set_age(p.get_age() + aging_interval); */
                /*       /1* cout << "Proc #" << p.get_pid() << " NEW AGE: " << p.get_age() << endl; *1/ */
                /*       queues[i].push(p); */
                /*       break; */
                /*   } */
                /* } */
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
                      cout << "Q" << i << ": Proc #" << pid << " finished in less than time quantum" << endl;
                      cout << "\t" << "Starting time: " << clock << endl;
                      cout << "\t" << "Ending time: " << clock+burst << endl;
                    #endif
                    clock = clock + burst;
                    p.set_waiting_time(clock - p.get_arrival());
                    p.set_turnaround_time((clock+burst)-p.get_arrival());
                    total_turnaround += p.get_turnaround_time();
                    total_waiting += p.get_waiting_time();
                    queues[i].pop();
                    break;
                }

                // Burst longer than time quantum - needs to be demoted
                else if(burst - time_quantum > 0 && i != num_queues-1)
                {
                    #ifdef DEBUG
                      cout << "Q" << i << ": Proc #" << pid << " did not complete process. Demoting" << endl;
                      cout << "\t" << "Starting time: " << clock << endl;
                      cout << "\t" << "Ending time: " << clock+time_quantum << endl;
                    #endif
                    clock = clock+time_quantum;
                    queues[i].pop();
                    p.decrease_burst(time_quantum);
                    if (i > 1) {
                        p.set_demotion_time(clock);
                    }
                    p.set_age(0);
                    demote_process(p, queues, i);
                    break;
                }
                else if (burst - time_quantum > 0 && i == num_queues -1)
                {
                    #ifdef DEBUG
                      cout << "Q" << i << ": Proc #" << pid << " in last queue finished remainder of burst: " << burst << endl;
                      cout << "\t" << "Starting time: " << clock << endl;
                      cout << "\t" << "Ending time: " << clock+burst << endl;
                    #endif
                    clock = clock + burst;
                    p.set_turnaround_time((clock+time_quantum)-p.get_arrival());
                    total_turnaround += p.get_turnaround_time();
                    total_waiting += p.get_waiting_time();
                    queues[i].pop();
                    break;
                }

                // Burst equal to time quantum - remove proc & move clock forward value of time quantum
                else
                {
                    #ifdef DEBUG
                      cout << "Q" << i << ": Proc #" << pid << " completed in the allotted space" << endl;
                      cout << "\t" << "Starting time: " << clock << endl;
                      cout << "\t" << "Ending time: " << clock+time_quantum << endl;
                    #endif
                    clock = clock + time_quantum;
                    p.set_turnaround_time((clock+time_quantum)-p.get_arrival());
                    total_turnaround += p.get_turnaround_time();
                    total_waiting += p.get_waiting_time();
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
    Proc_Table::print_averages(total_turnaround, total_waiting, total_processes);
    exit(0);
}
