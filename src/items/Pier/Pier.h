#pragma once

#include <memory>
#include <thread>
#include <mutex>

#include "Specification.h"
#include "IShip.h"

class Pier {
public:
    Pier(ContentType);
    ContentType getPierType();
    void simulateUnloading(std::unique_ptr<IShip>&);

private:
    std::thread mSimulationThread;
    std::mutex mMutex;

    ContentType mType;
};