#pragma once

#include <memory>

#include "ICapacity.h"
#include "Specification.h"

class Capacity : public ICapacity {
private:
    std::shared_ptr<CapacityType> m_capacity;
public:
    Capacity(CapacityType);
    ~Capacity();
    virtual std::shared_ptr<CapacityType> getCapacity();
};