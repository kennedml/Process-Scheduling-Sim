#ifndef WHS_PROC_H
#define WHS_PROC_H

#include "proc.h"

class WHS_Proc : public Proc
{
  public:
    int io;
    int current_priority;
    WHS_Proc(int in_pid, int in_burst, int in_arrival, int in_priority, int in_io, int in_current_priority) 
      : Proc(in_pid, in_burst, in_arrival, in_priority), io(in_io), current_priority(in_current_priority)
    {
        io = in_io;
        current_priority = in_current_priority;
    }
    WHS_Proc(){}
    ~WHS_Proc(){}

    void print_proc()
    {
      Proc::print_proc();
      cout << "I/O: " << io << endl;
    }

    struct WHS_Arrival_Compare {
      bool operator()(const WHS_Proc &p1, const WHS_Proc &p2) const {
        if(p1.get_arrival() == p2.get_arrival()) {
            if(p1.get_priority() == p2.get_priority()){
                return p1.get_pid() > p2.get_pid();
            }
          }
          else {
            return p1.get_arrival() > p2.get_arrival();
          }
        }
    };
    
    struct WHS_Priority_Compare {
      bool operator()(const WHS_Proc &p1, const WHS_Proc &p2) const {
        if(p1.get_priority() == p2.get_priority()) {
            return p1.get_pid() > p2.get_pid();
          }
          else {
            return p1.get_priority() < p2.get_priority();
          }
        }
    };
  
    void set_current_priority(int n){ current_priority = n; }
    void set_io(int n){ io = n; }
    int get_current_priority() const{ return current_priority; }
    int get_io() const{ return io; }

};

#endif
