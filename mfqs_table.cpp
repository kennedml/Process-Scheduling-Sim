#include "mfqs_table.h"

void MFQS_Table::print_attributes()
{
    cout << endl << "Num Queues:     " << num_queues << endl;
    cout << "Num Processes:  " << num_procs << endl;
    cout << "Starting TQ:    " << time_quantum << endl;
    cout << "Aging interval: " << aging_interval << endl << endl;
}

void MFQS_Table::init()
{
    // Create array of queues
    queue<MFQS_Proc> queues[num_queues];
    
    for(int i = 0; i < num_queues; i++)
    {
        queue<MFQS_Proc> procs;
        queues[i] = procs;
    }


    // Get info needed for processes
    cout << endl << "1) Use a file" << endl;
    cout << "2) Enter information manually" << endl;
    cout << endl << "Choose whether to use a file or to manually enter your information: ";

    int input;
    scanf("%d", &input);
    if(input == 1)
    {
        // TODO - Include head from file that has this function(on different laptop)
        cout << endl <<"Using a file" << endl << endl;
    }
    else if(input == 2)
    {
        cout << "Enter the number of processes you wish to enter: " << endl;
        cin >> num_procs;
        
        cout << "Enter the desired time quantum: " << endl;
        cin >> time_quantum;
        
        cout << "Enter the desired aging interval: " << endl;
        cin >> aging_interval;

        int pid, burst, arrival, priority;
        
        cout << "NUM PROC: " << num_procs << endl;
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

            MFQS_Proc proc(pid, burst, arrival, priority);
            queues[0].push(proc);
        }

    }
    else
    {
        cout << "WROOOOONG" << endl;
        exit(0);
        // TODO send user back to start of init
    }

    /*    
        int in_num_procs;
        int in_num_queue = -1;
        int in_starting_tq;
        int in_aging_interval;

        cout << "Enter the number of processes you would like to add: ";
        cin >> in_num_procs;
        //table.set_num_procs(in_num_procs);
        if(in_num_queue <= 0 || in_num_queue > 5)
        {
            cout << "Error: Invalid Range. Valid entries range from 1-5" << endl;
        }
    else
    {
        //table.set_num_queues(in_num_queue);
    }
  }
  cout << "Enter the desired time quantum: ";
  cin >> in_starting_tq;
  table.set_start_tq(in_starting_tq);

  cout << "Enter the desired aging interval: ";
  cin >> in_aging_interval;
  table.set_aging_interval(in_aging_interval);
    
    */

}

