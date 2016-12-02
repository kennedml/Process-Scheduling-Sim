#ifndef PROC_HANDLER_H
#define PROC_HANDLER_H

#include "mfqs_table.h"
#include "rts_table.h"
#include "whs_table.h"
#include "utilities.h"
#include <queue>
#include <vector>

using namespace std;

class Proc_Handler
{
  protected:
    int clock;
  public:
    Proc_Handler(){ clock = 0; }
    ~Proc_Handler(){}

    void run();

    void increment_clock(){ clock++; }
    int get_clock(){ return clock; }
};

#endif
