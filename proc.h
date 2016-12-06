#ifndef PROC_H
#define PROC_H

#include <iostream>
#include <string>

using namespace std;

class Proc
{
  private:
    int pid;
    int burst;
    int arrival;
    int priority;
    int deadline;
    int io;

  public:
    Proc(int pid, int burst, int arrival, int priority);
    Proc(){
        pid = 0;
        burst = 0;
        arrival = 0;
        priority = 0;
        deadline = 0;
        io = 0;
    }
    ~Proc(){}

    int get_pid() const { return pid; }
    int get_burst() const { return burst; }
    int get_arrival() const { return arrival; }
    int get_priority() const { return priority; }

    void decrease_burst(int n){ burst -= n;}
    void set_burst(int n){ burst = n; } 
    void print_proc();
    
    struct Compare {
      bool operator()(const Proc &p1, const Proc &p2) const {
        if(p1.arrival == p2.arrival) {
          return p1.pid > p2.pid;
        } else {
          return p1.arrival < p2.arrival;
        }
      }
    };
};

#endif
