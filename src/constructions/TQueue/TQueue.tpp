#pragma once
#include <thread>
#include <mutex>
#include <iostream>
//#include "TQueue.h"

template<class T>
TQueue<T>::TQueue(): isRun(true) {
    //mThread = std::thread(&TQueue::loop, this);
    mThread = std::thread(&TQueue::loop, this);
    std::cout << "constructor TQueue" << std::endl;
}

template<class T>
int TQueue<T>::loop() {
    std::cout << "running" << std::endl;
    while (isRun) {
        process();
    }
    return 0;
}

template<class T>
void TQueue<T>::process() {
    mQueueMutex.lock();
    //std::cout << "process" << std::endl;
    if (mQueue->empty()) {
        mQueueMutex.unlock();
        //std::cout << "process0" << std::endl;
        return;
    }
    //std::cout << "process1" << std::endl;
    std::unique_ptr<T> tmpDecision = std::move(mQueue->front());
    mQueueMutex.unlock();
    //std::cout << "process2" << std::endl;

    //std::cout << tmpDecision << std::endl;

    mQueueMutex.lock();
    if (!mQueue->empty()) {
        mQueue->pop();
    }
    mQueueMutex.unlock();
}

template<class T>
void TQueue<T>::pushEvent(T event) {
    //std::cout << "push" << std::endl;
    if (!isRun) {
        return;
    }
    std::unique_lock<std::mutex> lock(mQueueMutex);
    std::unique_ptr<T> wrapper = std::make_shared<T>(event);
    //std::cout << "push1" << std::endl;
    mQueue->push(wrapper);
    //std::cout << "push2" << std::endl;
}

template<class T>
void TQueue<T>::pushEvent(std::unique_ptr<T> event) {
    if (!isRun) {
        return;
    }
    mQueueMutex.lock();
    //std::unique_lock<std::mutex> lock(mQueueMutex);
    mQueue->push(std::move(event));
    mQueueMutex.unlock();
}

template<class T>
void TQueue<T>::halt() {
    isRun = false;
    std::cout << "halt()" << std::endl;
    if (mThread.joinable()) {
        mThread.join();
    }
}

template<class T>
TQueue<T>::~TQueue() {
    halt();
    std::cout << "TQueue destroyed" << std::endl;
}