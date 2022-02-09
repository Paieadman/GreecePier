#pragma once
#include "IShip.h"
#include "Capacity.h"
#include "Content.h"
#include "Specification.h"

class Ship : public IShip {
private:
    std::unique_ptr<Capacity> m_capacity;
    std::unique_ptr<Content> m_content;
public:
    Ship(CapacityType capacity, ContentType content);
    ~Ship();
    void sayHello();
    ContentType getShipType();
};