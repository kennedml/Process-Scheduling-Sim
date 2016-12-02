#ifndef MFQS_TABLE_H
#define MFQS_TABLE_H

#include "proc_table.h"
#include "mfqs_proc.h"
#include <queue>
#include <vector>

class MFQS_Table : public Proc_Table
{
    struct MFQS_Compare
    {
        bool operator()(const MFQS_Proc &p1, const MFQS_Proc &p2) const
        {
            int p1_value = 0;
            int p2_value = 1;
            return p1_value < p2_value;
        }
    };

    
  protected:
    int num_queues;
    int start_tq;
    int aging_interval;
  
  public:
    MFQS_Table()
    {
        num_queues = 0;
        start_tq = 0;
        aging_interval = 0;
    }
    ~MFQS_Table(){}

    int get_num_queues(){return num_queues;}
    void set_num_queues(int n)
    { 
        if( n <= 0 || n > 5)
        {
            
        }

        num_queues = n; 
    }
    
    int get_start_tq(){ return start_tq; }
    void set_start_tq(int n){ start_tq = n; }

    int get_aging_interval(){ return aging_interval; }
    void set_aging_interval(int n){ aging_interval = n; }

    void print_attributes()
    {
        cout << endl << "Num Queues:     " << num_queues << endl;
        cout << "Num Processes:  " << num_procs << endl;
        cout << "Starting TQ:    " << start_tq << endl;
        cout << "Aging interval: " << aging_interval << endl << endl;
    }
    

    //std::priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Compare> create_queues()
    //std::priority_queue create_queue(const int size)

    void enqueue_proc(MFQS_Proc *processes)
    {

    }
};
#endif
