#ifndef _FUCK_YOUR_ASS_ELEVATORFSM_H_
#define _FUCK_YOUR_ASS_ELEVATORFSM_H_

#include "State.h"
#include "Fsm.h"
#include <exception>

enum FSM_STATE
{
    FSM_STATE_CLOSE,
    FSM_STATE_OPEN,
    FSM_STATE_RUINNG,
    FSM_STATE_STOP,
    FSM_STATE_NULL,
};

enum FSM_EVENT
{
    FSM_EVENT_DOWN,
    FSM_EVENT_UP,
};

class Elevator : public IContext
{
public:
    Elevator() {
        SetState(FSM_STATE_CLOSE);
    }
    ~Elevator() { }
};

class StateClose : public IState<Elevator>
{
public:
    StateClose() { }
    virtual ~StateClose() { }
    virtual int OnStateChange(Elevator& ctx, uint32_t event) {
        printf("StateClose\n");
        return 0;
    }
    virtual uint32_t GetStateId() const {
        return FSM_STATE_CLOSE;
    }
};

class StateOpen : public IState<Elevator>
{
public:
    StateOpen () { }
    virtual ~StateOpen() { }
    virtual int OnStateChange(Elevator& ctx, uint32_t event) {
        printf("StateOpen\n");
        return 0;
    }
    virtual uint32_t GetStateId() const {
        return FSM_STATE_OPEN;
    }
};

class StateRunning : public IState<Elevator>
{
public:
    StateRunning () { }
    virtual ~StateRunning() { }
    virtual int OnStateChange(Elevator& ctx, uint32_t event) {
        printf("StateRunning\n");
        return 0;
    }
    virtual uint32_t GetStateId() const {
        return FSM_STATE_RUINNG;
    }
};

class StateStop : public IState<Elevator>
{
public:
    StateStop () { }
    virtual ~StateStop() { }
    virtual int OnStateChange(Elevator& ctx, uint32_t event) {
        printf("StateStop\n");
        return 0;
    }
    virtual uint32_t GetStateId() const {
        return FSM_STATE_STOP;
    }
};

class StateNull : public IState<Elevator>
{
public:
    StateNull () { }
    virtual ~StateNull() { }
    virtual int OnStateChange(Elevator& ctx, uint32_t event) {
        printf("StateNull\n");
        return 0;
    }
    virtual uint32_t GetStateId() const {
        return FSM_STATE_NULL;
    }
};

class ElevatorFsm : public Fsm<Elevator>
{
public:
    ElevatorFsm() : _state_close(NULL),
        _state_open(NULL),
        _state_running(NULL),
        _state_stop(NULL),
        _state_null(NULL)
    {
        try {
            _state_close = new StateClose();
            _state_open = new StateOpen();
            _state_running = new StateRunning();
            _state_stop = new StateStop();
            _state_null = new StateNull();
        } catch ( std::exception ex ) {
            printf("ElevatorFsm init fail : %s\n", ex.what());
            delete _state_close;
            delete _state_open;
            delete _state_running;
            delete _state_stop;
            delete _state_null;
        }

        _state_map.insert(std::make_pair(_GetKey(FSM_STATE_CLOSE, FSM_EVENT_DOWN), _state_open));
        _state_map.insert(std::make_pair(_GetKey(FSM_STATE_CLOSE, FSM_EVENT_UP), _state_open));
        _state_map.insert(std::make_pair(_GetKey(FSM_STATE_OPEN, FSM_EVENT_DOWN), _state_running));
        _state_map.insert(std::make_pair(_GetKey(FSM_STATE_OPEN, FSM_EVENT_UP), _state_running));
    }
    ~ElevatorFsm()
    {
        delete _state_close;
        delete _state_open;
        delete _state_running;
        delete _state_stop;
        delete _state_null;
    }
private:
    IState<Elevator>* _state_close;
    IState<Elevator>* _state_open;
    IState<Elevator>* _state_running;
    IState<Elevator>* _state_stop;
    IState<Elevator>* _state_null;
};

#endif
