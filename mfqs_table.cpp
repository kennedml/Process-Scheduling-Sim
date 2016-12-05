#include "mfqs_table.h"

void MFQS_Table::print_attributes()
{
    cout << endl << "Num Queues:     " << num_queues << endl;
    cout << "Num Processes:  " << num_procs << endl;
    cout << "Starting TQ:    " << time_quantum << endl;
    cout << "Aging interval: " << aging_interval << endl;
}

/*
void MFQS_Table::demote_process()
{

}
*/

void MFQS_Table::run()
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

        int pid, burst, arrival, priority, queue_level;
        
        priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Proc::MFQS_Compare> queue;
        
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
            queue.push(proc);
        }

        int clock = 0;
        int max =  500;

        for(int i = 0; i < num_queues; i++)
        {

        }
        while(clock < max)
        {
	    MFQS_Proc p = queue.top();
            if(p.get_arrival() <= clock)
            {
                queue.pop();
            }
            else
            {
            }
            clock++;
        }

        /*
        while (!queue.empty())
	{
		MFQS_Proc p = queue.top();
		p.print_attributes();
		queue.pop();
	}
        */

    }
    else
    {
        cout << "WROOOOONG" << endl;
        exit(0);
        // TODO send user back to start of init
    }
}

