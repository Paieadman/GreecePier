#pragma once

#include "Specification.h"

class ICapacity {
public:
    virtual std::shared_ptr<CapacityType> getCapacity() = 0;
};