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

Ship* ShipGenerator::createShip(CapacityType capacity) {
    return new Ship(capacity);
}

//TODO add 
Ship* ShipGenerator::createRandomShip() {
    CapacityType capacity = getRandomCapacity();
    return createShip(capacity);
}

//TODO make it random
// CapacityType ShipGenerator::getRandomCapacity() {
//     // std::srand(std::time(nullptr));
//     // int random_variable = std::rand()%1000;
//     std::unique_ptr<CapacityType> capacityType = std::make_unique<CapacityType>(CapacityType::BIG);
//     return capacityType;

// }