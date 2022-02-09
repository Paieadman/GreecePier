#pragma once

#include <memory>

#include "ICapacity.h"
#include "Specification.h"

class Capacity : public ICapacity {
private:
    CapacityType m_capacity;
public:
    Capacity(CapacityType);
    ~Capacity();
    virtual CapacityType getCapacity();
};