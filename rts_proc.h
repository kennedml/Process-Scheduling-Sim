#ifndef RTS_PROC_H
#define RTS_PROC_H

#include "proc.h"

class RTS_Proc : public Proc
{
  public:
    int deadline;

    RTS_Proc(int in_pid = 0, int in_burst = 0, int in_arrival = 0, int in_priority = 0, int in_deadline = 0) 
      : Proc(in_pid, in_burst, in_arrival, in_priority), deadline(in_deadline){}
    ~RTS_Proc(){}

    void print_proc() {
      Proc::print_proc();
      cout << "Deadline: " << deadline << endl;
    }


    struct arrival_compare : Proc::Compare {
      bool operator()(const RTS_Proc &p1, const RTS_Proc &p2) const {
        return p1.arrival < p2.arrival;
      }
    };

    struct deadline_compare : Proc::Compare {
      bool operator()(const RTS_Proc &p1, const RTS_Proc &p2) const {
        if(p1.deadline == p2.deadline) {
          if(p1.arrival == p2.arrival) {
            return p1.pid > p2.pid;
          } else {
            return p1.arrival < p2.arrival;
          }
        } else {
          return p1.deadline > p2.deadline;
        }
      }
    };
};

#endif
