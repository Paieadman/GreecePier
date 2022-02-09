#pragma once

#include <memory>

#include "Specification.h"

class ICapacity {
public:
    virtual CapacityType getCapacity() = 0;
    virtual ~ICapacity() = default;
};