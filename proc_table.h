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

    int get_num_procs()
    {
      cout << "Num procs in parent function: " << num_procs << endl;
      return num_procs;
    }

    void increment_procs(){ num_procs++; }
    void decrement_procs(){ num_procs--; }
};

#endif
