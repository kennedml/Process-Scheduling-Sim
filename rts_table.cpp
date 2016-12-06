#include "rts_table.h"

void RTS_Table::run(string path){
  arrival_queue queue = import_file(path);
}

arrival_queue RTS_Table::import_file(string path){
  ifstream file;
  file.open(path);
  string process;
  string str;
  int pid, burst, arrival, priority, deadline, io;

  arrival_queue queue;

  getline(file,process);
  while(getline(file,process)){
    istringstream ss(process);

    ss >> pid >> burst >> arrival >> priority >> deadline >> io;

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
      queue.push(temp);
    }
  }
  file.close();

  return queue;
}
