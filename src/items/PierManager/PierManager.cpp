

#include "PierManager.h"
#include "IShip.h"

PierManager::PierManager() {
    //mPiercesMap 
}

void PierManager::sendShip(std::unique_ptr<IShip>& ship) {
    mPiercesMap.at(ship->getShipType())->simulateUnloading(ship);
}