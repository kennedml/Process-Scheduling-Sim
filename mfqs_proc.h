#ifndef MFQS_PROC_H
#define MFQS_PROC_H

#include "proc.h"

class MFQS_Proc : public Proc
{
  
  protected:
      int queue_level;
  
  public:
    MFQS_Proc(int in_pid = 0, int in_burst = 0, int in_arrival = 0, int in_priority = 0) //, int in_cost = 0 ) 
      : Proc(in_pid, in_burst, in_arrival, in_priority) //cost(in_cost)
    {
      pid = in_pid;
      burst = in_burst;
      arrival = in_arrival;
      priority = in_priority;
      queue_level = 0;
    }
    ~MFQS_Proc(){}

    struct MFQS_Compare
    {
        bool operator()(const MFQS_Proc &p1, const MFQS_Proc &p2) const
        {
            if(p1.get_arrival() == p2.get_arrival())
            {
                if(p1.get_pid() == p2.get_pid())
                {
                    return p1.get_pid() > p2.get_pid();
                }
                else
                {
                    return p1.get_priority() < p2.get_priority();
                }
            }
            else
            {
                return p1.get_arrival() > p2.get_arrival();
            }
        }
    };
    
    int get_pid() const{ return pid; }
    int get_burst() const{ return burst; }
    int get_arrival() const{ return arrival; }
    int get_priority() const{ return priority; }
    int get_queue_level() const{ return queue_level; } 
    
    
    void set_burst(int n){ burst = n; } 

    void print_attributes();
};

#endif
