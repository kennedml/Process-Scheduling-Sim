#include "proc_handler.h"

void Proc_Handler::run(){
  int table_type;

  table_type = get_table_type();
  if(table_type == 4)
    exit(0);
  //Manual or File
  
  switch(table_type) {
    case 1: { 
      int num_queues;
      cout << "Enter number of queues from 1-5" << endl;
      cin >> num_queues;
      MFQS_Table table(num_queues);
      table.run();
      break;
    }
    case 2: {
      RTS_Table rts_table;
      rts_table.run();
      break;
    }
    case 3: {
      //WHS
      cout << "WHS" << endl;
      break;
    }
  }
}

