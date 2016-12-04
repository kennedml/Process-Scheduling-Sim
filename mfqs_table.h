#ifndef MFQS_TABLE_H
#define MFQS_TABLE_H

#include "proc_table.h"
#include "mfqs_proc.h"
#include <queue>
#include <vector>


class MFQS_Table : public Proc_Table
{
    /*
    struct MFQS_Compare
    {
        bool operator()(const MFQS_Proc &p1, const MFQS_Proc &p2) const
        {
            int p1_value = 0;
            int p2_value = 1;
            return p1_value < p2_value;
        }
    };
    */

    
  protected:
    int num_queues;
    int num_procs;
    int time_quantum;
    int aging_interval;
  
  public:
    MFQS_Table(int num_queues)
    {
        this->num_queues = num_queues;
    }
    ~MFQS_Table(){}

    int get_num_queues(){return num_queues;}
    void set_num_queues(int n){ num_queues = n;} 
    int get_time_quantum(){ return time_quantum; }
    void set_time_quantum(int n){ time_quantum = n; }

    int get_aging_interval(){ return aging_interval; }
    void set_aging_interval(int n){ aging_interval = n; }

    void init();

    void print_attributes();
    
    
    

    //std::priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Compare> create_queues()
    //std::priority_queue create_queue(const int size)
    /*
    void enqueue_proc(MFQS_Proc *processes)
    {

    }
    */
};
#endif
