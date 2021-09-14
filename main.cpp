#include <iostream>
#include "ShipGenerator.h"
#include "Ship.h"

int main() {
    std::cout << "hi" << std::endl;
    //Ship* sh = new Ship();
    ShipGenerator* shipGenerator = new ShipGenerator();
    Ship* ship = shipGenerator->createRandomShip();
    ship->sayHello();
    return 0;
}