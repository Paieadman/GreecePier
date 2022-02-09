#pragma once

#include "Specification.h"

class IShip {
public:
    // IShip() = default;
    virtual void sayHello() = 0;
    virtual ~IShip() = default;
    virtual ContentType getShipType() = 0;
    // IShip(IShip&) = default;
    // IShip(IShip&&) = default;
};