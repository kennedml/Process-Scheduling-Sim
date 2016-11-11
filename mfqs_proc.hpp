#ifndef MFQS_PROC_HPP
#define MFQS_PROC_HPP

#include "proc.hpp"

class MFQS_Proc : public Proc
{
  public:
    MFQS_Proc(int in_pid = 0, int in_burst = 0, int in_arrival = 0, int in_priority = 0) //, int in_cost = 0 ) 
      : Proc(in_pid, in_burst, in_arrival, in_priority) //cost(in_cost)
    {
      pid = in_pid;
      burst = in_burst;
      arrival = in_arrival;
      priority = in_priority;
    }
    ~MFQS_Proc(){}
};

#endif
