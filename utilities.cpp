#include "utilities.h"

int get_table_type()
{
  
  int table_type;
    
  cout << "1) MFQS(Multi-level Feedback Queue Scheduler" << endl;
  cout << "2) RTS(Real-Time Scheduler" << endl;
  cout << "3) WHS(Windows Hybrid Scheduler" << endl;
  cout << "4) Exit Program" << endl;
  cout << endl << "Choose your algorithm: ";

  
  scanf("%d", &table_type);

  return table_type;

  /*
  if(table_type == 4)
    exit(0);
  //Manual or File
  
  switch(table_type){
    case 1:
    {  
        cout << "Enter number of queues from 1-5" << endl;
        scanf("%d", &num_queues);
        MFQS_Table table(num_queues);
        table.init();
        break;
    }
    case 2:
    {
        //RTS
        cout << "RTS" << endl;
        break;
    }
    case 3:
    {
        //WHS
        cout << "WHS" << endl;
        break;
    }
    case 4:
        exit(0);
  }
  */
}


bool from_file(){
  cout << "0) Enter processes manually" << endl;
  cout << "1) Processes from file" << endl;

  int file_manual;
  scanf("%d", &file_manual);
  return file_manual;
}
