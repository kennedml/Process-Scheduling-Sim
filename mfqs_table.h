#ifndef MFQS_TABLE_H
#define MFQS_TABLE_H

#include "proc_table.h"
#include "mfqs_proc.h"
#include <queue>
#include <vector>


class MFQS_Table : public Proc_Table
{

    
  protected:
    int num_queues;
    int num_procs;
    int aging_interval;
  
  public:
    MFQS_Table(int num_queues)
    {
        this->num_queues = num_queues;
    }
    ~MFQS_Table(){}

    int get_num_queues(){return num_queues;}
    void set_num_queues(int n){ num_queues = n;} 

    int get_aging_interval(){ return aging_interval; }
    void set_aging_interval(int n){ aging_interval = n; }
    void demote_process(MFQS_Proc &proc, vector<priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Proc::MFQS_Compare> > &queues, int idx);
    void promote_process(MFQS_Proc &proc, vector<priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Proc::MFQS_Compare> > &queues,int idx);    
    void run();

    void print_attributes();
    bool all_empty(vector<priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Proc::MFQS_Compare> > &queues);
    
    

    //std::priority_queue<MFQS_Proc, vector<MFQS_Proc>, MFQS_Compare> create_queues()
    //std::priority_queue create_queue(const int size)
    /*
    void enqueue_proc(MFQS_Proc *processes)
    {

    }
    */
};
#endif
