#pragma once


SigHandler::SigHandler() {
    signal(SIGINT, onSignal);
}

SigHandler* SigHandler::getInstance() {
    static SigHandler* instance = new SigHandler();
    return instance;
}

void SigHandler::onSignal(int sig) {
    getInstance()->mSignal = sig;
    getInstance()->mCV.notify_all();
    std::cout << "onSignal" << std::endl;
    // exit(1);
}

int SigHandler::waitSignal() {
    std::unique_lock<std::mutex> lock(mMutex);
    mCV.wait(lock);
    std::cout << "waitSignal" << std::endl;
    return mSignal;
}