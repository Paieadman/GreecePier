#include <iostream>
#include <memory>

#include "ShipGenerator.h"
#include "Ship.h"

int main() {
    std::cout << "hi" << std::endl;
    //Ship* sh = new Ship();
    auto shipGenerator = ShipGenerator::getInstance();
    auto ship = shipGenerator->createRandomShip();
    ship->sayHello();
    return 0;
}