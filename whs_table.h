#ifndef WHS_TABLE_H
#define WHS_TABLE_H

#include "proc_table.h"
#include "whs_proc.h"
#include <queue>

class WHS_Table : public Proc_Table
{
  protected:

  public:
    WHS_Table(){}
    ~WHS_Table(){}

    void demote_hb_process(WHS_Proc &proc, priority_queue<WHS_Proc, vector<WHS_Proc>, WHS_Proc::WHS_Priority_Compare> queue, int tq);
    
    void demote_lb_process(WHS_Proc &proc, priority_queue<WHS_Proc, vector<WHS_Proc>, WHS_Proc::WHS_Priority_Compare> queue, int tq);
    
    void run();

};

#endif
