#include <iostream>
#include <memory>

#include "Capacity.h"
#include "ICapacity.h"
#include "Specification.h"

Capacity::Capacity(CapacityType capacity): m_capacity(capacity) {
    //m_capacity = std::make_shared<CapacityType>(capacity);
    //std::cout << "Capacity constructor" << std::endl;
}

Capacity::~Capacity() {
    //std::cout << "Capacity destructor" << std::endl;
}

CapacityType Capacity::getCapacity() {
    return m_capacity;
}