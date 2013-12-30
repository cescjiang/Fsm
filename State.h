#ifndef _FUCK_YOUR_ASS_STATE_H_
#define _FUCK_YOUR_ASS_STATE_H_

#include <cstdio>
#include <stdint.h>

template<typename Context>
class IState
{
public:
    IState() { }
    virtual ~IState() { }
    virtual int OnStateChange(Context&, uint32_t) = 0;
    virtual uint32_t GetStateId() const = 0;
    void SetContextState(Context& ctx, uint32_t state) {
        ctx.SetState(state);
    }
};

class IContext
{
public:
    IContext() { }
    virtual ~IContext() { }
    uint32_t GetState() {
        return _state;
    }
    void SetState(uint32_t val) {
        _state = val;
    }
private:
    uint32_t _state;
};

#endif
