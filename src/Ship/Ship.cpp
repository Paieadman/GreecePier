#include <iostream>

#include "Ship.h"
#include "Capacity.h"

Ship::Ship(CapacityType capacity) {
    m_capacity = std::make_unique<Capacity>(capacity);
    // Capacity::Capacity(capacity);
    std::cout << "ship created" << std::endl;
}

Ship::~Ship() {
    std::cout << "ship destroyed" << std::endl;
}

void Ship::sayHello() {
    std::cout << "Hi, i am ship" << std::endl;
}