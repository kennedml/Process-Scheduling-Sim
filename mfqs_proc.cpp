#include "mfqs_proc.h"

void MFQS_Proc::print_attributes()
{
    cout << "Pid:  " << this->get_pid() << endl;
    cout << "Burst:  " << this->get_burst() << endl;
    cout << "Arrival:  " << this->get_arrival() << endl;
    cout << "Priority:  " << this->get_priority() << endl;
}
