#include "whs_table.h"
#include <queue>


void WHS_Table::demote_hb_process(WHS_Proc &proc, priority_queue<WHS_Proc, vector<WHS_Proc>, WHS_Proc::WHS_Priority_Compare> queue, int tq)
{
    cout << "DEMOTING HIGH BAND PROCESS" << endl;
    cout << "ORIGINAL PRIORITY: " << proc.get_priority() << endl; 
    if(proc.get_current_priority() <= proc.get_priority())
        proc.set_priority(proc.get_current_priority());
    else if(proc.get_current_priority() > proc.get_priority())
    {
        proc.set_priority(proc.get_priority());
    }
    
    cout << "Re-inserting into high_band process with priority = " << proc.get_priority() << endl;
    queue.push(proc);
}

void WHS_Table::demote_lb_process(WHS_Proc &proc, priority_queue<WHS_Proc, vector<WHS_Proc>, WHS_Proc::WHS_Priority_Compare> queue, int tq)
{
    cout << "DEMOTING LOW BAND PROCESS" << endl;
    cout << "ORIGINAL PRIORITY: " << proc.get_priority() << endl; 
    if(proc.get_current_priority() <= proc.get_priority())
        proc.set_priority(proc.get_current_priority());
    else if(proc.get_current_priority() > proc.get_priority())
    {
        proc.set_priority(proc.get_priority());
    }
    cout << "Re-inserting into low_band process with priority = " << proc.get_priority() << endl;
    queue.push(proc);
}

void WHS_Table::run()
{
    priority_queue<WHS_Proc, vector<WHS_Proc>, WHS_Proc::WHS_Arrival_Compare> arrivals;
    priority_queue<WHS_Proc, vector<WHS_Proc>, WHS_Proc::WHS_Priority_Compare> high_band; 
    priority_queue<WHS_Proc, vector<WHS_Proc>, WHS_Proc::WHS_Priority_Compare> low_band; 
    priority_queue<WHS_Proc, vector<WHS_Proc>, WHS_Proc::WHS_Priority_Compare> ios; 

    int aging_interval, time_quantum;
    
    cout << "Enter the desired time quantum: " << endl;
    cin >> time_quantum;
    cout << "Enter the desired aging interval: " << endl;
    cin >> aging_interval;
    // Get info needed for processes
    cout << endl << "1) Use a file" << endl;
    cout << "2) Enter information manually" << endl;
    cout << endl << "Choose whether to use a file or to manually enter your information: ";

    int input;
    cin >> input;
    
    int pid, burst, arrival, priority, queue_level, deadline, io;
    
    
    if(input == 1)
    {
        cout << "Please enter the file path: ";
        string path;
        cin >> path;
        ifstream file;
        file.open(path);
        string process;
        string str;
        vector<WHS_Proc> processes;

        getline(file,process);
        while(getline(file,process)){
            istringstream ss(process);

            ss >> pid >> burst >> arrival >> priority >> deadline >> io;
            if(pid < 0 || burst < 0 || arrival < 0 || priority < 0 || priority > 99 || deadline < 0 || io < 0)
            {
                continue;
            }
            else
            {
                WHS_Proc proc(pid, burst, arrival, priority, 0, priority);
                cout << "Pushing Proc" << endl;
                arrivals.push(proc);
                
                /*if(priority >=50)
                    high_band.push(proc);
                else if(priority<50)
                    low_band.push(proc);
                */
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
                WHS_Proc proc(pid, burst, arrival, priority, 0, priority);
                arrivals.push(proc);
                /*
                if(priority >=50)
                    high_band.push(proc);
                else if(priority<50)
                    low_band.push(proc);
                */
            }
        }

    }
    else
    {
        cout << "WROOOOONG" << endl;
        exit(0);
        // TODO send user back to start of init
    }
    cout << "Arrivals size: " << arrivals.size() << endl;
    cout << endl;
    
    int clock = 0;
    //while(!arrivals.empty() || !high_band.empty() || !low_band.empty() || ios.empty())
    while(!arrivals.empty() || !high_band.empty())
    {
        // If there is any procs in the high band, do those first
        if(!arrivals.empty())
        {
            WHS_Proc p;
            p = arrivals.top();
            if(p.get_arrival() <= clock)
            {
                if(p.get_priority() >= 50)
                {
                    cout << "PUSHING PID #" << p.get_pid() << " to high band" << endl;
                    high_band.push(p);
                }
                else if(p.get_priority() < 50)
                {    cout << "PUSHING PID #" << p.get_pid() << " to low band" << endl;
                     low_band.push(p);
                }
                arrivals.pop();
            }
            
        }
        cout << "CLOCK: " << clock << endl;
        if(!high_band.empty())
        {
            cout << "STUFF IN HIGH BAND" << endl;
            WHS_Proc p;
            p = high_band.top();

            // Finishes in less than TQ
            if(p.get_burst() - time_quantum < 0)
            {
                cout << "High Band" << ": Proc #" << pid << " finished in less than time quantum" << endl;
                cout << "\t" << "Starting time: " << clock << endl;
                clock = clock + p.get_burst();
                cout << "\t" << "Ending time: " << clock << endl;
                high_band.pop();
                continue;
            }

            // Doesn't finish in time. Demote
            else if(p.get_burst() - time_quantum > 0)
            {
                p.set_current_priority(priority - time_quantum);
                cout << "Demoting Proc #" << pid << endl;
                p.decrease_burst(time_quantum);
                clock = clock + time_quantum;
                // TODO Demote
                high_band.pop();
                demote_hb_process(p, high_band, clock);
            }
            else if(p.get_burst() - time_quantum == 0)
            {
                cout << "High band: Proc #" << pid << " finished exactly in the time quantum." << endl;
                cout << "\t" << "Starting time: " << clock << endl;
                clock = clock + time_quantum;
                cout << "\t" << "Ending time: " << clock << endl;
                high_band.pop();
                continue;
            }

            // Finishing in exactly the time quantum.                    

        }
        else if(!low_band.empty())
        {
            cout << "STUFF IN LOW BAND" << endl;
            WHS_Proc p;
            p = low_band.top();

            // Finishes in less than TQ
            if(p.get_burst() - time_quantum < 0)
            {
                cout << "Low Band" << ": Proc #" << pid << " finished in less than time quantum" << endl;
                cout << "\t" << "Starting time: " << clock << endl;
                clock = clock + p.get_burst();
                cout << "\t" << "Ending time: " << clock << endl;
                low_band.pop();
                continue;
            }

            // Doesn't finish in time. Demote
            else if(p.get_burst() - time_quantum > 0)
            {
                cout << "Demoting Proc #" << pid << endl;
                p.decrease_burst(time_quantum);
                clock = clock + time_quantum;
                // TODO Demote
                low_band.pop();
                demote_lb_process(p, low_band, clock);
            }
            else if(p.get_burst() - time_quantum == 0)
            {
                cout << "High band: Proc #" << pid << "finished exactly in the time quantum." << endl;
                cout << "\t" << "Starting time: " << clock << endl;
                clock = clock + time_quantum;
                cout << "\t" << "Ending time: " << clock << endl;
                low_band.pop();
                continue;
            }

            // Finishing in exactly the time quantum.                    

        }
        else
            cout << "EMPTY HIGH BAND" << endl;
        
        cout << "ARRIVALS SZ: " << arrivals.size() << endl;
        cout << "HIGH BAND SZ: " << high_band.size() << endl;
        cout << "LOW BAND SZ: " << low_band.size() << endl << endl;
        clock++;
        
        
        /*
        if(!high_band.empty())
        {
            cout << "ENTERING HIGH BAND" << endl;
            WHS_Proc p;
            p = high_band.top();
            if(p.get_arrival() < clock)
            {
                cout << "RUNNING PROC" << endl;
                // Time quantum is greater than burst
                if(p.get_burst() - time_quantum < 0)
                {
                    cout << "High Band" << ": Proc #" << pid << " finished in less than time quantum" << endl;
                    cout << "\t" << "Starting time: " << clock << endl;
                    clock = clock + p.get_burst();
                    cout << "\t" << "Starting time: " << clock << endl;
                    high_band.pop();
                    continue;
                }
                // Burst is greater than time quantum. Run for TQ then demote.
                else if(p.get_burst() - time_quantum > 0)
                {
                    cout << "Demoting Proc #" << pid << endl;
                    high_band.pop();
                    p.decrease_burst(time_quantum);
                    clock = clock + p.get_burst();
                    //
                    //if (i > 1) {
                    //    p.demotion_time = clock;
                    //}
                    //
                    demote_hb_process(p, high_band, time_quantum);
                    continue;
                }
                else if(p.get_burst() - time_quantum == 0)
                {
                    cout << "High band: Proc #" << pid << "finished exactly in the time quantum." << endl;
                    high_band.pop();
                    clock = clock + time_quantum;
                    continue;
                }
            }
            else
                cout << "NO PROCESS AT " << clock << endl;
                clock++;
        }
        // If not do the low band
        else
        {
            cout << "ENTERING LOW BAND" << endl;
            WHS_Proc p;
            p = low_band.top();
            if(p.get_arrival() < clock)
            {
                cout << "RUNNING PROCESS" << endl;
                // Time quantum is greater than burst
                if(p.get_burst() - time_quantum < 0)
                {
                    cout << "Low Band" << ": Proc #" << pid << " finished in less than time quantum" << endl;
                    clock = clock + p.get_burst();
                    low_band.pop();
                    continue;
                }
                // Burst is greater than time quantum. Run for TQ then demote.
                else if(p.get_burst() - time_quantum > 0)
                {
                    low_band.pop();
                    p.decrease_burst(time_quantum);
                    clock = clock + p.get_burst();
                    demote_lb_process(p, low_band,time_quantum);
                    //if (i > 1) {
                    //    p.demotion_time = clock;
                    //}
                    //demote_process(p, queues, i);
                    //
                    continue;
                }
                else if(p.get_burst() - time_quantum == 0)
                {
                    cout << "Low band: Proc #" << pid << "finished exactly in the time quantum." << endl;
                    low_band.pop();
                    clock = clock + time_quantum;
                    continue;
                }
            }
            else
                clock++;
            
        }
    */
    }
}
