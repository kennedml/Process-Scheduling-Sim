#include "rts_table.h"

void RTS_Table::run(){
  int clock = 0;
  // Get info needed for processes
  int pid, burst, arrival, priority,deadline;

  int hard;
  cout << "Hard or Soft RTS?" << endl;
  cout << "1)Soft\n2)Hard" << endl;
  cin >> hard;

  int input = from_file();
  arrival_queue arr_queue;
  deadline_queue dead_queue;
  if(input == 1) {
    cout << "Please enter the file path: ";
    string path;
    cin >> path;
    arr_queue = import_file(path);
  }
  else if(input == 2) {
    cout << "Enter the number of processes you wish to enter: " << endl;
    cin >> num_procs;

    for(int i = 0; i < num_procs; i++)
    {
      cout << "************* Process " << i << " **************" << endl;
      cout << endl << "Enter PID: ";
      cin >> pid;
      cout << "Enter burst: ";
      cin >> burst;
      cout << "Enter arrival: ";
      cin >> arrival;
      cout << "Enter priority: ";
      cin >> priority;
      cout << "Enter deadline: ";
      cin >> deadline;
    
      if(pid < 0 || burst < 0 || arrival < 0 || deadline < 0)
      {
        cout << "Invalid proc. Pid #" << pid << endl;
        continue;
      }
      else
      {
        cout << "Pushing Proc" << endl;
        RTS_Proc proc(pid, burst, arrival, priority, deadline);
        arr_queue.push(proc);
      }
    }

  }
  else
  {
    cout << "WROOOOONG" << endl;
    exit(0);
  }

  double total_procs = arr_queue.size();
  double total_turnaround = 0;
  double total_waiting = 0;
  vector<RTS_Proc> failed;

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
          failed.push_back(arr);
          if (hard){
              cout << "RTS Hard was selected, Process Rejected caused failure" << endl;
              exit(1);
          }
          total_procs--;
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
        cout << "Proc #" << pid << " finished in time." << endl;
        cout << "\tStarting time: " << dead.get_starting_time() << endl;
        cout << "\tEnding time: " << clock << endl;

        total_turnaround += clock-dead.get_arrival();
        total_waiting += clock - dead.get_arrival() - dead.get_starting_burst();
        continue;
      }else{
        dead.decrease_burst(1);
        dead_queue.push(dead);
      }
    }
    clock++;
  }
  Proc_Table::print_averages(total_turnaround, total_waiting, total_procs);
  if (!failed.empty()){
      cout << "Processes that failed" << endl;
      while(!failed.empty()){
          RTS_Proc p = failed.back();
          failed.pop_back();
          cout << "P" << p.get_pid() << ", ";
      }
      cout << endl;
  }
}

arrival_queue RTS_Table::import_file(string path){
  ifstream file;
  file.open(path.c_str());
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
      /* DEBUG_PRINT(("=== CLEANED:\t%s\n", process.c_str())); */
      cout << "=== CLEANED:\t" << process << endl;
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
  /* DEBUG_PRINT(("\nSanitized %d Processes Due To Negative Values\n", sanitized)); */
  cout << "Sanitized " << sanitized << " Processes from input due to negative values!" << endl;

  return queue;
}


bool RTS_Table::all_empty(arrival_queue &arr_queue,deadline_queue &dead_queue){
  return (arr_queue.empty() && dead_queue.empty());
}
