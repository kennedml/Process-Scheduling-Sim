#ifndef RTS_TABLE_H
#define RTS_TABLE_H

#include "proc_table.h"
#include "rts_proc.h"
#include <queue>
#include <vector>

typedef priority_queue<RTS_Proc, vector<RTS_Proc>, RTS_Proc::arrival_compare> arrival_queue;
typedef priority_queue<RTS_Proc, vector<RTS_Proc>, RTS_Proc::deadline_compare> deadline_queue;

class RTS_Table : public Proc_Table
{
  private:

  public:
    RTS_Table(){}
    ~RTS_Table(){}
    void run(string path);
    arrival_queue import_file(string path);
    bool all_empty(arrival_queue arr_queue,deadline_queue dead_queue);

};

#endif
