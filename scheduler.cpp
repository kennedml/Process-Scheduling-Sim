#include "proc_handler.h"

#define MFQS                1
#define RTS                 2
#define WHS                 3
#define EXIT_PROGRAM        4


int main()
{ 
  Proc_Handler handler;
  handler.run();
  return 0;
}
