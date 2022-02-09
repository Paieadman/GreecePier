#pragma once

#include <vector>

#include "Specification.h"

class StateMachine {
private:
    void setStateInit();
    void setStateRun();
    void setStateStop();
public:
    void setState(State);
    virtual ~StateMachine();
    StateMachine();
};