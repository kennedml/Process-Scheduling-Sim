#ifndef WHS_PROC_H
#define WHS_PROC_H

#include "proc.h"

class WHS_Proc : public Proc
{
  public:
    int io;

    WHS_Proc(int in_pid = 0, int in_burst = 0, int in_arrival = 0, int in_priority = 0, int in_io = 0) 
      : Proc(in_pid, in_burst, in_arrival, in_priority), io(in_io)
    {
      pid = in_pid;
      burst = in_burst;
      arrival = in_arrival;
      priority = in_priority;
    }
    ~WHS_Proc(){}

    void print_proc()
    {
      Proc::print_proc();
      cout << "I/O: " << io << endl;
    }
};

#endif
