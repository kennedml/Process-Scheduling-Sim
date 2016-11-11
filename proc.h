#ifndef PROC_H
#define PROC_H

#include "utilities.h"

class Proc
{
  protected:
    int pid;
    int burst;
    int arrival;
    int priority;

  public:
    Proc(int id = 0, int in_burst = 0, int in_arrival = 0, int in_priority = 0) 
      : pid(id), burst(in_burst), arrival(in_arrival), priority(in_priority) 
    {

    }
    ~Proc(){}

    int get_pid() const { return pid; }
    int get_burst() const { return burst; }
    int get_arrival() const { return arrival; }
    int get_priorty() const { return priority; }
    void print_proc()
    {
      cout << "PID: " << pid << endl;
      cout << "Burst: " << burst << endl;
      cout << "Arrival: " << arrival << endl;
      cout << "Priority: " << priority << endl;
    }
};

#endif
