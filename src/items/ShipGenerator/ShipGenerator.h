#pragma once

#include <memory>

#include "IShip.h"
#include "IShipGenerator.h"
#include "Specification.h"

class ShipGenerator : public IShipGenerator {
    // const static std::shared_ptr<ShipGenerator> m_instance;
public:
    ShipGenerator();
    static std::shared_ptr<ShipGenerator> getInstance();

    virtual ~ShipGenerator();
    virtual std::unique_ptr<IShip> createShip(CapacityType, ContentType);
    virtual std::unique_ptr<IShip> createRandomShip();
};