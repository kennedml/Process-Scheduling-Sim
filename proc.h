#ifndef PROC_H
#define PROC_H

#include <iostream>
#include <string>

using namespace std;

class Proc
{
  protected:
    int pid;
    int burst;
    int arrival;
    int priority;
    int deadline;
    int io;

  public:
    Proc(int pid, int burst, int arrival, int priority, int deadline, int io);
    ~Proc(){}

    int get_pid() const { return pid; }
    int get_burst() const { return burst; }
    int get_arrival() const { return arrival; }
    int get_priorty() const { return priority; }
    void print_proc();
};

#endif
