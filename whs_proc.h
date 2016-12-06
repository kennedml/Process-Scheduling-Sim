#ifndef WHS_PROC_H
#define WHS_PROC_H

#include "proc.h"

class WHS_Proc : public Proc
{
  public:
    int io;

    WHS_Proc(int in_pid, int in_burst, int in_arrival, int in_priority, int in_io) 
      : Proc(in_pid, in_burst, in_arrival, in_priority), io(in_io)
    {
        io = in_io;
    }
    WHS_Proc(){}
    ~WHS_Proc(){}

    void print_proc()
    {
      Proc::print_proc();
      cout << "I/O: " << io << endl;
    }

    struct WHS_Compare {
      bool operator()(const WHS_Proc &p1, const WHS_Proc &p2) const {
        if(p1.get_priority() == p2.get_priority()) {
            return p1.get_pid() > p2.get_pid();
          }
          else {
            return p1.get_priority() < p2.get_priority();
          }
        }
    };
   
    int get_arrival() const{ return arrival; }
    int get_priority() const{ return priority; }
    int get_pid() const{ return pid; }
    int get_io() const{ return io; }
};

#endif
