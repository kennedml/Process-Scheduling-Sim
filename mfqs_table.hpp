#ifndef MFQS_TABLE_HPP
#define MFQS_TABLE_HPP

#include "proc_table.hpp"
#include "mfqs_proc.hpp"

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
