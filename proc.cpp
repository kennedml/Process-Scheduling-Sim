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
  cout << "PID\tBURST\tARRIVAL\tPRIORITY\tDEADLINE\tIO" << endl;
  cout << pid << "\t" << burst << "\t" << arrival << "\t" << priority << "\t\t" << deadline << "\t\t" << io << endl;
}
