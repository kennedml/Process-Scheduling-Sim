#include "rts_table.h"

void RTS_Table::run(string path){
  cout << "JENNY I'M RUNNIGN!" << endl;
  int clock = 0;
  arrival_queue arr_queue = import_file(path);
  deadline_queue dead_queue;

  while(!all_empty(arr_queue, dead_queue)){
    RTS_Proc arr = arr_queue.top();
    if (arr.get_arrival() <= clock){
      int slack = arr.get_deadline() - arr.get_arrival() - arr.get_burst();
      cout << "PID: " << arr.get_pid() << " SLACK: " << slack << endl;
      if (slack >= 0){
        dead_queue.push(arr);
        arr_queue.pop();
      }
    } 
    if (!dead_queue.empty()){
      RTS_Proc dead = dead_queue.top();

      int burst         = dead.get_burst();
      int pid           = dead.get_pid();
      int deadline      = dead.get_deadline();

      cout << "Proc #" << pid << endl;

      if (dead.get_starting_time() == 0){
        dead.set_starting_time(clock);
        cout << "Starting Proc #" << pid << " at " << dead.get_starting_time() << endl;
      }

      dead.decrease_burst(1);
      if (burst <= 0){
        cout << "Proc #" << pid << " finished in time." << endl;
        cout << "\tStarting time: " << dead.get_starting_time() << endl;
        cout << "\tEnding time: " << clock << endl;
        dead_queue.pop();
        break;
      }
    }
    clock++;
  }
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

    if (deadline < 0 || burst < 0 || arrival < 0 || priority < 0 || io < 0){
      DEBUG_PRINT(("!! Skipping Process Due To Negative Values On RTS !!\n"));
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


bool RTS_Table::all_empty(arrival_queue arr_queue,deadline_queue dead_queue){
  if (arr_queue.empty() && dead_queue.empty())
    return true;
  return false;
}
