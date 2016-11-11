#include "proc_handler.h"

#define MFQS                1
#define RTS                 2
#define WHS                 3
#define EXIT_PROGRAM        4

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
