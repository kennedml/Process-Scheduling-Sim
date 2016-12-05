#include "proc.h"

Proc::Proc(int pid, int burst, int arrival, int priority) {
  this->pid = pid;
  this->burst = burst;
  this->arrival = arrival;
  this->priority = priority;
}

void Proc::print_proc(){
  cout << "PID\tBURST\tARRIVAL\tPRIORITY" << endl;
  cout << pid << "\t" << burst << "\t" << arrival << "\t" << priority << endl;
}
