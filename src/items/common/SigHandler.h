#pragma once
#include <signal.h>
#include <condition_variable>
#include <iostream>
#include <mutex>

class SigHandler {
public:
    int waitSignal();
    static SigHandler* getInstance();

private:
    static void onSignal(int sig);
    SigHandler();

    std::mutex mMutex;
    std::condition_variable mCV;
    static constexpr int NOSIGNAL = -1;
    int mSignal = NOSIGNAL;
};

#include "SigHandler.ipp"