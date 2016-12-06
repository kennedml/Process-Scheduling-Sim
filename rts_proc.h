#ifndef RTS_PROC_H
#define RTS_PROC_H

#include "proc.h"

class RTS_Proc : public Proc
{
  public:
    int deadline;
    int starting_time;

    RTS_Proc(int in_pid, int in_burst, int in_arrival, int in_priority, int in_deadline) 
      : Proc(in_pid, in_burst, in_arrival, in_priority), deadline(in_deadline){
      starting_time = 0; 
      }
    ~RTS_Proc(){}

    int get_deadline() const{ return deadline; }
    int get_starting_time() const{ return starting_time; } 

    void set_starting_time(int n){ this->starting_time = n; } 

    void print_proc() {
      Proc::print_proc();
      cout << "Deadline: " << deadline << endl;
    }


    struct arrival_compare {
      bool operator()(const RTS_Proc &p1, const RTS_Proc &p2) const {
        if (p1.arrival == p2.arrival){
          if (p1.deadline == p2.deadline){
            return p1.pid > p2.pid;
          } else{
            return p1.deadline > p2.deadline;
          }
        } else {
          return p1.arrival > p2.arrival;
        }
      }
    };

    struct deadline_compare {
      bool operator()(const RTS_Proc &p1, const RTS_Proc &p2) const {
        if(p1.deadline == p2.deadline) {
          if(p1.arrival == p2.arrival) {
            return p1.pid > p2.pid;
          } else {
            return p1.arrival > p2.arrival;
          }
        } else {
          return p1.deadline > p2.deadline;
        }
      }
    };
};

#endif
