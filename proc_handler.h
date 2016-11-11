#ifndef PROC_HANDLER_H
#define PROC_HANDLER_H

#include "mfqs_table.h"
#include "rts_table.h"
#include "whs_table.h"

class Proc_Handler
{
  protected:
    int clock;
  public:
    Proc_Handler(){ clock = 0; }
    ~Proc_Handler(){}

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

    void increment_clock(){ clock++; }
    int get_clock(){ return clock; }
};

#endif
