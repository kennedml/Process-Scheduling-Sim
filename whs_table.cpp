#include "whs_table.h"
#include <queue>

void WHS_Table::run()
{
    priority_queue<WHS_Proc, vector<WHS_Proc>, WHS_Proc::WHS_Compare> high_band; 
    priority_queue<WHS_Proc, vector<WHS_Proc>, WHS_Proc::WHS_Compare> low_band; 
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
                WHS_Proc proc(pid, burst, arrival, priority, 0);
                if(priority >=50)
                    high_band.push(proc);
                else if(priority<50)
                    low_band.push(proc);
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
                WHS_Proc proc(pid, burst, arrival, priority, 0);
                if(priority >=50)
                    high_band.push(proc);
                else if(priority<50)
                    low_band.push(proc);
            }
        }

    }
    else
    {
        cout << "WROOOOONG" << endl;
        exit(0);
        // TODO send user back to start of init
    }

    cout << "Number procs low band: " << low_band.size() << endl;
    cout << "Number procs high band: " << high_band.size() << endl;

    int clock = 0;
    while(!low_band.empty() || !high_band.empty())
    {
        // If there is any procs in the high band, do those first
        if(!high_band.empty())
        {
            WHS_Proc p;
            p = high_band.top();
            cout << "HIGH BAND PRIORITY: " << p.get_priority() << endl;
            high_band.pop();
        }
        // If not do the low band
        else
        {
            WHS_Proc p;
            p = low_band.top();
            cout << "LOW BAND PRIORITY: " << p.get_priority() << endl;
            low_band.pop();
        }
        clock++;
    }
}
