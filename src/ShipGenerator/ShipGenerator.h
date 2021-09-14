#pragma once

#include "Ship.h"
#include "IShipGenerator.h"
#include "Specification.h"

class ShipGenerator : public IShipGenerator {
public:
    ShipGenerator();
    virtual ~ShipGenerator();
    virtual Ship* createShip(CapacityType);
    virtual Ship* createRandomShip();
};