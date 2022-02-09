#pragma once

#include <signal.h>

#include <mutex>
#include <condition_variable>

class SHandler {
    public:
        static constexpr int NOSIGNAL = -1;

    public:
        SHandler() {
            struct sigaction sigIntHandler;
            sigIntHandler.sa_handler = SHandler::signalHandler;
            sigemptyset(&sigIntHandler.sa_mask);
            sigIntHandler.sa_flags = 0;
            sigaction(SIGINT, &sigIntHandler, NULL);
        }
        virtual ~SHandler() {}

        bool isSignal() {
            return m_isSignal;
        }

        int waitSignal() {
            std::unique_lock<std::mutex> lock(m_waitConditionMutex);
            if (!m_isSignal) {
                m_waitCondition.wait(lock);
            }
            return m_signal;
        }
    private:
        static void signalHandler(int s) {
            m_isSignal = true;
            m_signal = s;
            m_waitCondition.notify_all();
        }

    private:
        static bool m_isSignal;
        static int m_signal;
        static std::mutex m_waitConditionMutex;
        static std::condition_variable m_waitCondition;
};

bool SHandler::m_isSignal = false;
int SHandler::m_signal = SHandler::NOSIGNAL;
std::mutex SHandler::m_waitConditionMutex;
std::condition_variable SHandler::m_waitCondition;
