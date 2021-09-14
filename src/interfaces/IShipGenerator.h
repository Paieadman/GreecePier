#pragma once
#include "IShip.h"
#include "Specification.h"

class IShipGenerator {
public:
    //virtual IShipGenerator() = 0;
    //IShipGenerator();
    //virtual ~IShipGenerator() = 0;
    virtual std::unique_ptr<Ship> createRandomShip() = 0;
    virtual std::unique_ptr<Ship> createShip(CapacityType, ContentType) = 0;
};