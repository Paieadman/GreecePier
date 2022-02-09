#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>

#include "ShipGenerator.h"
#include "Ship.h"
#include "Specification.h"

ShipGenerator::ShipGenerator() {
    std::cout << "ShipGenerator created" << std::endl;
}

ShipGenerator::~ShipGenerator() {
    std::cout << "ShipGenerator destroyed" << std::endl;
}

std::shared_ptr<ShipGenerator> ShipGenerator::getInstance() {
    static std::shared_ptr<ShipGenerator> instance = std::make_shared<ShipGenerator>();
    return instance;
}

std::unique_ptr<IShip> ShipGenerator::createShip(CapacityType capacity, ContentType content) {
    return std::make_unique<Ship>(capacity, content);
}

//TODO add 
std::unique_ptr<IShip> ShipGenerator::createRandomShip() {
    CapacityType capacity = getRandomCapacity();
    ContentType content = getRandomContent();
    return createShip(capacity, content);
}

//TODO make it random
// CapacityType ShipGenerator::getRandomCapacity() {
//     // std::srand(std::time(nullptr));
//     // int random_variable = std::rand()%1000;
//     std::unique_ptr<CapacityType> capacityType = std::make_unique<CapacityType>(CapacityType::BIG);
//     return capacityType;

// }