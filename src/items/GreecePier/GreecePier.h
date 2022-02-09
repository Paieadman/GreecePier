#pragma once

#include <memory>
#include <atomic>

#include "IShipGenerator.h"
#include "TQueueImpl.h"
#include "PierManager.h"


class GreecePier {
public:
    GreecePier();
    void start();
    void stop();
    virtual ~GreecePier();

private:
    const GreecePier& operator=(const GreecePier&) = delete;
    const GreecePier&& operator=(const GreecePier&&) = delete;

    GreecePier(GreecePier&) = delete;
    GreecePier(GreecePier&&) = delete;

    //members
    std::unique_ptr<PierManager> mPierManager;
    std::unique_ptr<IShipGenerator> mShipGenerator;
    std::unique_ptr<TQueueImpl<IShip>> mQueue;
    std::atomic<bool> isExit;
    std::unique_ptr<std::thread> workingThread;
};