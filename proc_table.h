#ifndef PROC_TABLE_H
#define PROC_TABLE_H

#include "proc.h"

class Proc_Table
{
  protected:
    int num_procs;

  public:
    Proc_Table()
    {
      num_procs = 0;
    }
    ~Proc_Table(){}

    int get_num_procs(){ return num_procs; }
    void set_num_procs(int n){ num_procs = n; }
    void increment_procs(){ num_procs++; }
    void decrement_procs(){ num_procs--; }

};

#endif
