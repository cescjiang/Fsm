#include "State.h"
#include "ElevatorFsm.h"

int main()
{
    ElevatorFsm fsm;
    Elevator elv;
    fsm.Transfer(elv, FSM_EVENT_DOWN);
    fsm.Transfer(elv, FSM_EVENT_DOWN);
    fsm.Transfer(elv, FSM_EVENT_DOWN);
    return 0;
}
