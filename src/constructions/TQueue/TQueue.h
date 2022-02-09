#pragma once
#include <queue>
#include <string>
#include <atomic>
#include <mutex>
#include <memory>
#include <thread>
#include <chrono>

template <class T>
class TQueue {
public:
    TQueue();
    virtual ~TQueue();
    void pushEvent(T);
    void pushEvent(std::unique_ptr<T>);

protected:
    std::mutex mQueueMutex;
    std::unique_ptr<std::queue<std::unique_ptr<T>>> mQueue = std::make_unique<std::queue<std::unique_ptr<T>>>();
    std::atomic<bool> isRun;
    std::thread mThread;

    virtual void process();
    void halt();

    //unsupported
    TQueue(TQueue&& obj) = delete;
    TQueue(const TQueue & obj) = delete;
    TQueue& operator=(const TQueue& obj) = delete;
    TQueue& operator=(TQueue&& obj) = delete;

protected:
    int loop();
};

#include "TQueue.tpp"