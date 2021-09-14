#pragma once
#include "IShip.h"
#include "Capacity.h"

class Ship : public IShip {
private:
    std::unique_ptr<Capacity> m_capacity;
public:
    Ship(CapacityType capacity);
    ~Ship();
    virtual void sayHello();
};