#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MFQS                1
#define RTS                 2
#define WHS                 3
#define EXIT_PROGRAM        4

using namespace std;


// Base Class
class Proc
{

    protected:

        int pid;
        int burst;
        int arrival;
        int priority;
    
    public:
        

        Proc(int id = 0, int in_burst = 0, int in_arrival = 0, int in_priority = 0) 
                    : pid(id), burst(in_burst), arrival(in_arrival), priority(in_priority) 
        {

        }

    int get_pid() const 
    { 
        return pid; 
    }

    int get_burst() const 
    { 
        return burst; 
    }

    int get_arrival() const 
    { 
        return arrival; 
    }
    
    int get_priorty() const 
    { 
        return priority; 
    }

    void print_proc()
    {
        cout << "PID: " << pid << endl;
        cout << "Burst: " << burst << endl;
        cout << "Arrival: " << arrival << endl;
        cout << "Priority: " << priority << endl;
    }
};


// TODO - Check if this includes a deadline (don't think it does)
class MFQS_Proc : public Proc
{
    public:

        MFQS_Proc(int in_pid = 0, int in_burst = 0, int in_arrival = 0, int in_priority = 0) //, int in_cost = 0 ) 
                : Proc(in_pid, in_burst, in_arrival, in_priority) //cost(in_cost)
        {
            pid = in_pid;
            burst = in_burst;
            arrival = in_arrival;
            priority = in_priority;
        }
       
};

class RTS_Proc : public Proc
{
    public:

        int deadline;

        RTS_Proc(int in_pid = 0, int in_burst = 0, int in_arrival = 0, int in_priority = 0, int in_deadline = 0) 
                : Proc(in_pid, in_burst, in_arrival, in_priority),  
                  deadline(in_deadline)
        {
            pid = in_pid;
            burst = in_burst;
            arrival = in_arrival;
            priority = in_priority;
        }

        void print_proc()
        {
            Proc::print_proc();
            cout << "Deadline: " << deadline << endl;
        }
};



// TODO - Check to see if this requires a deadline
class WHS_Proc : public Proc
{
    public:

        int io;

        WHS_Proc(int in_pid = 0, int in_burst = 0, int in_arrival = 0, int in_priority = 0, int in_io = 0) 
                : Proc(in_pid, in_burst, in_arrival, in_priority),  
                  io(in_io)
        {
            pid = in_pid;
            burst = in_burst;
            arrival = in_arrival;
            priority = in_priority;
        }

        void print_proc()
        {
            Proc::print_proc();
            cout << "I/O: " << io << endl;
        }
};

class Proc_Table
{
    public:
    
        Proc_Table()
        {
            num_procs = 0;
        }

        int get_num_procs()
        {
            cout << "Num procs in parent function: " << num_procs << endl;
            return num_procs;
        }
    
        void increment_procs()
        {
            num_procs++;
        }
        
        void decrement_procs()
        {
            num_procs--;
        }
    
    protected:
        
        int num_procs;

};

class MFQS_Table : public Proc_Table
{
    public:
        MFQS_Table()
        {
            
        }   
    
    MFQS_Proc create_queue(int size)
    {
        MFQS_Proc processes[size];
        //MFQS_Proc process(pid, burst, arrival, priority);
    }
    
    void enqueue_proc(MFQS_Proc processes[])
    {

    }
    
    protected:
        int num_queues;
};

class RTS_Table : public Proc_Table
{
    public:
        RTS_Table(){}       
    
    protected:

};
class WHS_Table : public Proc_Table
{
    public:
        WHS_Table(){}       
    
    protected:

};

class Proc_Handler
{
    public:
        Proc_Handler()
        {
            clock = 0;
        }


        void run(int table_type)
        {
            int pid, burst, arrival, priority;

            if(table_type == 1)
            {
                

                // Create MQFS table
                MFQS_Table table;

                int num_procs = table.get_num_procs();
                cout << "Number of processes: " << cout << num_procs << endl;
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
                    cout << endl << "Doin it the old fashioned way" << endl << endl;
                }
                else
                {
                    cout << endl << "Please enter a valid menu choice" << endl;
                    run(table_type);
                }

                // Reset any data that may have been used from a previous loop
                clock = 0;
            }
            else if(table_type == 2)
            {
                cout << "Table Type 2" << endl;
            }
            else if(table_type == 3)
            {
                cout << "Table Type 3" << endl;
            }
            else
            {
                exit(0);
            }
        }

        void increment_clock()
        {
            clock++;
        }

        int get_clock()
        {
            return clock;
        }

    protected:
        int clock;
};

int print_menu()
{
    cout << "1) MFQS(Multi-level Feedback Queue Scheduler" << endl;
    cout << "2) RTS(Real-Time Scheduler" << endl;
    cout << "3) WHS(Windows Hybrid Scheduler" << endl;
    cout << "4) Exit Program" << endl;
    cout << endl << "Choose your algorithm: ";
    
    int input;
    scanf("%d", &input);
    return input; 

}

int main()
{ 
    int rc = 0;

    Proc_Handler handler;
    
    
    while(1)
    {
        rc = print_menu();
        // Check to make sure its a valid menu selection
        // TODO define upper and lower menu bounds
        if(rc <= 0 || rc > 4)
        {
            cout << endl << "Invalid menu choice. Please enter a valid menu number" << endl << endl;
            rc = print_menu();
            continue;
        }
        else
        {
            handler.run(rc);
        }
    }
    
    // Determine algorithm type 
    

    /*
    //MFQS_Proc proc1(112,42, 2, 4);
    MFQS_Table table1;
    //table1.increment_procs();
    int ret = table1.get_num_procs();
//    proc1.print_proc();
    cout << "return is: " << ret << endl; 
    */
    return 0;
}
