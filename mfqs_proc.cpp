#include "mfqs_proc.h"

void MFQS_Proc::print_attributes()
{
    cout << "Pid:  " << pid << endl;
    cout << "Burst:  " << burst << endl;
    cout << "Arrival:  " << arrival << endl;
    cout << "Priority:  " << priority << endl;
    cout << "Queue level: " << queue_level << endl;
}
