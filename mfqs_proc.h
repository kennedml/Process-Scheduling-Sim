#ifndef MFQS_PROC_H
#define MFQS_PROC_H

#include "proc.h"

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

    struct MFQS_Compare
    {
        bool operator()(const MFQS_Proc &p1, const MFQS_Proc &p2) const
        {
            int p1_arrival = p1.get_arrival();
            int p2_arrival = p2.get_arrival();
            int p1_priority = p1.get_priority();
            int p2_priority = p2.get_priority();
            
            if(p1_arrival == p2_arrival)
            {
                return p1_priority < p2_priority;
            }
            else
            {
                return p1_arrival > p2_arrival;
            }


        }
    };
    int get_pid() const{ return pid; }
    int get_burst() const{ return burst; }
    int get_arrival() const{ return arrival; }
    int get_priority() const{ return priority; }

    void set_burst(int n){ burst = n; }

    void print_attributes();
};

#endif
