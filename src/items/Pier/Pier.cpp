
#include <memory>
#include <thread>
#include <iostream>

#include "Pier.h"
#include "Specification.h"
#include "IShip.h"

Pier::Pier(ContentType type): mType(type) {}


//add mutex on class member thread it provide one-by-one execution
//and call constructor of thhread to member thread
void Pier::simulateUnloading(std::unique_ptr<IShip>& ship) {
    ship.reset(nullptr);
    //std::chrono::duration<double> simTime(0.1);
    // mMutex.lock();
    // mSimulationThread = std::thread([ship = std::move(ship)]() {
    //         using namespace std::chrono_literals;
    //         std::this_thread::sleep_for(100ms);
    //         //std::cout << typeid(ship).name() << std::endl;
    //         //ship.reset(nullptr);
    //         // mMutex->unlock();
    //     }
    // );
    // t.detach();
}

ContentType Pier::getPierType() {
    return mType;
}