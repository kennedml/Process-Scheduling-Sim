#ifndef RTS_PROC_H
#define RTS_PROC_H

#include "proc.h"

class RTS_Proc : public Proc
{
  public:
    int deadline;

    RTS_Proc(int in_pid = 0, int in_burst = 0, int in_arrival = 0, int in_priority = 0, int in_deadline = 0) 
      : Proc(in_pid, in_burst, in_arrival, in_priority),  
      deadline(in_deadline)
    {
      pid = in_pid;
      burst = in_burst;
      arrival = in_arrival;
      priority = in_priority;
    }
    ~RTS_Proc(){}

    void print_proc()
    {
      Proc::print_proc();
      cout << "Deadline: " << deadline << endl;
    }
};

#endif
