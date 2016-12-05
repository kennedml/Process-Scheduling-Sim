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

  /*
  if(table_type == 4)
    exit(0);
  //Manual or File
  
  switch(table_type){
    case 1:
    {  
        cout << "Enter number of queues from 1-5" << endl;
        cin >> num_queues;
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
  cin >> file_manual;
  return file_manual;
}

vector<Proc> import_file(string path, string type){
  ifstream file;
  file.open(path);
  string process;
  string str;
  vector<Proc> processes;
  int pid, burst, arrival, priority, deadline, io;
  bool rts = type == "rts" ? true : false;

  getline(file,process);
  while(getline(file,process)){
    istringstream ss(process);

    ss >> pid >> burst >> arrival >> priority >> deadline >> io;

    if (rts){
      if (deadline < 0){
        DEBUG_PRINT(("!! Skipping Process Due To Negative Deadline On RTS !!\n"));
        DEBUG_PRINT(("SKIPPED: %s\n", process.c_str()));
        continue;
      }
      else {
        RTS_Proc temp(pid, burst, arrival, priority, deadline);  
        #ifdef DEBUG
          temp.print_proc();
        #endif
        processes.push_back(temp);
      }
    }
    else{
      /* Generic Process */
      Proc temp(pid, burst, arrival, priority);
      #ifdef DEBUG
        temp.print_proc();
      #endif
      processes.push_back(temp);
    }
  }
  file.close();

  return processes;
}
