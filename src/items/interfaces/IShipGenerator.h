#pragma once
#include "IShip.h"
#include "Specification.h"

class IShipGenerator {
public:
    //virtual IShipGenerator() = 0;
    //IShipGenerator();
    virtual ~IShipGenerator() = default;
    virtual std::unique_ptr<IShip> createRandomShip() = 0;
    virtual std::unique_ptr<IShip> createShip(CapacityType, ContentType) = 0;
};