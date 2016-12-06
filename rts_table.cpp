#include "rts_table.h"

void RTS_Table::run(string path){
  int clock = 0;
  arrival_queue arr_queue = import_file(path);
  deadline_queue dead_queue;

  while(!all_empty(arr_queue, dead_queue)){
    if (!arr_queue.empty()){
      RTS_Proc arr = arr_queue.top();
      if (arr.get_arrival() <= clock){
        int slack = arr.get_deadline() - arr.get_arrival() - arr.get_burst();
        if (slack >= 0){
          /* #ifdef DEBUG */
          /*   cout << "=== INSERT PID: " << arr.get_pid() << " CLOCK: " << clock << " SLACK: " << slack << endl; */
          /* #endif */
          dead_queue.push(arr);
          arr_queue.pop();
        }else{
          cout << "=== RTS Process Rejected #" << arr.get_pid() << endl;
          arr.print_proc();
          arr_queue.pop();
        }
      } 
    }
    if (!dead_queue.empty()){
      RTS_Proc dead = dead_queue.top();
      dead_queue.pop();

      int pid = dead.get_pid();

      if (dead.get_starting_time() == 0){
        dead.set_starting_time(clock);
        #ifdef DEBUG
          cout << "Starting Proc #" << pid << " at " << dead.get_starting_time() << endl;
        #endif
      }


      if (dead.get_burst() <= 0){
        clock += dead.get_burst();
        #ifdef DEBUG
          cout << "Proc #" << pid << " finished in time." << endl;
          cout << "\tStarting time: " << dead.get_starting_time() << endl;
          cout << "\tEnding time: " << clock << endl;
        #endif
        continue;
      }else{
        dead.decrease_burst(1);
        dead_queue.push(dead);
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
  int sanitized = 0;
  DEBUG_PRINT(("=== \t\tPid\tBst\tArr\tPri\tDline\tI/O\n"));
  while(getline(file,process)){
    istringstream ss(process);

    ss >> pid >> burst >> arrival >> priority >> deadline >> io;

    if (deadline < 0 || burst < 0 || arrival < 0 || priority < 0 || io < 0){
      DEBUG_PRINT(("=== CLEANED:\t%s\n", process.c_str()));
      sanitized++;
      continue;
    }
    else {
      RTS_Proc temp(pid, burst, arrival, priority, deadline);  
      /* #ifdef DEBUG */
      /*   temp.print_proc(); */
      /* #endif */
      queue.push(temp);
    }
  }
  file.close();
  DEBUG_PRINT(("\nSanitized %d Processes Due To Negative Values\n", sanitized));

  return queue;
}


bool RTS_Table::all_empty(arrival_queue &arr_queue,deadline_queue &dead_queue){
  return (arr_queue.empty() && dead_queue.empty());
}
