#pragma once
#include "IShip.h"
#include "Specification.h"

class IShipGenerator {
public:
    //virtual IShipGenerator() = 0;
    //IShipGenerator();
    //virtual ~IShipGenerator() = 0;
    virtual Ship* createRandomShip() = 0;
    virtual Ship* createShip(CapacityType) = 0;
};