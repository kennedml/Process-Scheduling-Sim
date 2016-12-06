#include "utilities.h"

int get_table_type()
{
  int table_type;
    
  cout << "1) MFQS(Multi-level Feedback Queue Scheduler" << endl;
  cout << "2) RTS(Real-Time Scheduler" << endl;
  cout << "3) WHS(Windows Hybrid Scheduler" << endl;
  cout << "4) Exit Program" << endl;
  cout << endl << "Choose your algorithm: ";

  cin >> table_type;
  return table_type;
}


int from_file(){
  cout << "1) Processes from file" << endl;
  cout << "2) Enter processes manually" << endl;

  int file_manual;
  cin >> file_manual;
  return file_manual;
}
