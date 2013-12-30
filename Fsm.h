#ifndef _FUCK_YOUR_ASS_FSM_H_
#define _FUCK_YOUR_ASS_FSM_H_

#include "State.h"
#include <map>
#include <stdint.h>
#include <cassert>

template <typename Context>
class Fsm
{
public:
    Fsm() { }
    ~Fsm() { }
    typedef std::map<uint32_t, IState<Context>* > _StateTransferMap;
    int Transfer(Context& ctx, uint32_t event)
    {
        uint32_t key = _GetKey(ctx.GetState(), event);
        typename _StateTransferMap::iterator it = _state_map.find(key);
        if ( it == _state_map.end() ) {
            printf("Can't find state %u, %u\n", ctx.GetState(), event);
            return -1;
        }
        it->second->SetContextState(ctx, it->second->GetStateId());
        it->second->OnStateChange(ctx, event);
        return 0;
    }
protected:
    uint32_t _GetKey(uint32_t state, uint32_t event)
    {
        assert(state <= 0xffff);
        assert(event <= 0xffff);
        return (state << 16) | event;
    }
protected:
    _StateTransferMap _state_map;
};

#endif
