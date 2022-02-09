
#include <memory>
#include <thread>
#include <iostream>

#include "GreecePier.h"
#include "ShipGenerator.h"
#include "TQueueImpl.h"
#include "PierManager.h"

GreecePier::GreecePier() {
    mShipGenerator = std::make_unique<ShipGenerator>();
    isExit = false;
    mPierManager = std::make_unique<PierManager>();
}

void GreecePier::start() {
    mQueue = std::make_unique<TQueueImpl<IShip> >(std::bind(&PierManager::sendShip, std::ref(mPierManager), std::placeholders::_1));
    workingThread = std::make_unique<std::thread>(
        [this]() {
            while(!isExit) {
                auto ship = mShipGenerator->createRandomShip();
                //ship->sayHello();
                mQueue->pushEvent(std::move(ship));
            }
        }
    );
}

void GreecePier::stop() {
    isExit = true;
    if (workingThread->joinable()) {
        workingThread->join();
    }
}

GreecePier::~GreecePier() {
    stop();
    std::cout << "~GreecePier" << std::endl;
}