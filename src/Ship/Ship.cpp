#include <iostream>

#include "Ship.h"
#include "Capacity.h"
#include "Content.h"

Ship::Ship(CapacityType capacity, ContentType content) {
    m_capacity = std::make_unique<Capacity>(capacity);
    m_content = std::make_unique<Content>(content);
    // Capacity::Capacity(capacity);
    std::cout << "ship created" << std::endl;
}

Ship::~Ship() {
    std::cout << "ship destroyed" << std::endl;
}

void Ship::sayHello() {
    std::cout << "Hi, i am ship" << std::endl;
}