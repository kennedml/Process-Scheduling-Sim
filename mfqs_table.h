#ifndef MFQS_TABLE_H
#define MFQS_TABLE_H

#include "proc_table.h"
#include "mfqs_proc.h"

class MFQS_Table : public Proc_Table
{
  protected:
    int num_queues;

  public:
    MFQS_Table(){}
    ~MFQS_Table(){}

    MFQS_Proc* create_queue(const int size)
    {
      //MFQS_Proc process(pid, burst, arrival, priority);
      MFQS_Proc *processes = new MFQS_Proc[size];

      return processes;
    }

    void enqueue_proc(MFQS_Proc *processes)
    {

    }
};

#endif
