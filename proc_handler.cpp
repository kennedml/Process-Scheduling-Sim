#include "proc_handler.h"

void Proc_Handler::run(){
  int table_type = 0, pid = 0, burst = 0, arrival = 0, priority = 0, io = 0, deadline = 0;

  get_user_input(table_type, pid, burst, arrival, priority, io, deadline);
  /*

     if(table_type == 1)
     {
  // Create MQFS table
  //MFQS_Table table;

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
  int in_num_procs;
  int in_num_queue = -1;
  int in_starting_tq;
  int in_aging_interval;

  cout << "Enter the number of processes you would like to add: ";
  cin >> in_num_procs;
  //table.set_num_procs(in_num_procs);
  while(in_num_queue <= 0 || in_num_queue > 5)
  {
  cout << "Enter the number of queues you would like to use (max=5): ";
  cin >> in_num_queue;
  if(in_num_queue <= 0 || in_num_queue > 5)
  {
  cout << "Error: Invalid Range. Valid entries range from 1-5" << endl;
  }
  else
  {
  //table.set_num_queues(in_num_queue);
  }
  }
  cout << "Enter the desired time quantum: ";
  cin >> in_starting_tq;
  table.set_start_tq(in_starting_tq);

  cout << "Enter the desired aging interval: ";
  cin >> in_aging_interval;
  table.set_aging_interval(in_aging_interval);

  // Create Table queues
  //priority_queue<MFQS_Proc, vector<MFQS_Proc>, table.MFQS_Compare> *queue;
  table.create_queues();

  cout << "===========================================================" << endl;
  cout << "                     Process Entry" << endl;

  cout << "===========================================================" << endl;
  int in_pid;
  int in_burst;
  int in_arrival;
  int in_priority;

  for(int i = 0; i < table.get_num_procs(); i++)
  {
  cout << "************* Process " << i << " **************" << endl;
  cout << "    Enter PID: ";
  cin >> in_pid;
  cout << "    Enter burst: ";
  cin >> in_burst;
  cout << "    Enter arrival: ";
  cin >> in_arrival;
  cout << "    Enter priority: ";
  cin >> in_priority;

  MFQS_Proc proc(in_pid, in_burst, in_arrival, in_priority);


  //table.enqueue_proc(proc);
  cout << "pid: " << in_pid << "   burst: " << in_burst <<
    "   arrival: " << in_arrival << "   priority: " << in_priority << endl;
}
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

*/
}
