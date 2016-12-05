#include "proc.h"

Proc::Proc(int pid, int burst, int arrival, int priority, int deadline, int io) {
  this->pid = pid;
  this->burst = burst;
  this->arrival = arrival;
  this->priority = priority;
  this->deadline = deadline;
  this->io = io;
}

void Proc::print_proc(){
  cout << "PID: " << pid << endl;
  cout << "Burst: " << burst << endl;
  cout << "Arrival: " << arrival << endl;
  cout << "Priority: " << priority << endl;
  cout << "Deadline: " << deadline << endl;
  cout << "IO: " << io << endl;
}
