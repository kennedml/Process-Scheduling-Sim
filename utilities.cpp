#include "utilities.h"

void get_user_input(int& table_type, int& pid, int& burst, int& arrival, int& priority, int& io, int& deadline)
{
  cout << "1) MFQS(Multi-level Feedback Queue Scheduler" << endl;
  cout << "2) RTS(Real-Time Scheduler" << endl;
  cout << "3) WHS(Windows Hybrid Scheduler" << endl;
  cout << "4) Exit Program" << endl;
  cout << endl << "Choose your algorithm: ";

  scanf("%d", &table_type);

  if(table_type == 4)
    exit(0);
  //Manual or File
  switch(table_type){
    case 1:
    {  
        //MFQS
        MFQS_Table table;
        cout << "MFQS" << endl;
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
  }
}


bool from_file(){
  cout << "0) Enter processes manually" << endl;
  cout << "1) Processes from file" << endl;

  int file_manual;
  scanf("%d", &file_manual);
  return file_manual;
}
