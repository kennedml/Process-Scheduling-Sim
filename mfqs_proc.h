#ifndef MFQS_PROC_H
#define MFQS_PROC_H

#include "proc.h"

class MFQS_Proc : public Proc
{

  public:
    int queue_level;
    int demotion_time;
    int age;
    MFQS_Proc(int in_pid, int in_burst, int in_arrival, int in_priority, int demotion_time) //, int in_cost = 0 ) 
      : Proc(in_pid, in_burst, in_arrival, in_priority) //cost(in_cost)
    {
      queue_level = 0;
      age = 0;
      this->demotion_time = demotion_time;
    }
    MFQS_Proc(){}
    ~MFQS_Proc(){}

    struct MFQS_Compare {
      bool operator()(const MFQS_Proc &p1, const MFQS_Proc &p2) const {
        if(p1.get_arrival() == p2.get_arrival()) {
          if(p1.get_priority() == p2.get_priority()) {
            return p1.get_pid() > p2.get_pid();
          }
          else {
            return p1.get_priority() < p2.get_priority();
          }
        }
        else {
          return p1.get_arrival() > p2.get_arrival();
        }
      }
    };

    int get_pid() const{ return pid; }
    int get_burst() const{ return burst; }
    int get_arrival() const{ return arrival; }
    int get_priority() const{ return priority; }
    int get_queue_level() const{ return queue_level; } 
    int get_demotion_time() const{ return demotion_time; }
    int get_age() const{ return age; }


    void set_age(int n){age += n;}
    void decrease_burst(int n){ burst = burst - n;}
    void set_demotion_time(int n){ demotion_time = n; }
    void set_burst(int n){ burst = n; } 

    void print_attributes();
};

#endif
