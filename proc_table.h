#ifndef PROC_TABLE_H
#define PROC_TABLE_H

#include "utilities.h"


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
    void print_averages(const double &total_turnaround, const double &total_waiting, const double &total_procs){
      cout << "Average waiting time: " << total_waiting / total_procs << endl;
      cout << "Average turnaround time: " << total_turnaround / total_procs << endl;
      cout << "Total Processes Scheduled: " << total_procs << endl;
    }
};


#endif
