#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

#include "Manager.h"
#include "IManager.h"

using namespace std::chrono_literals;

Manager::Manager(const std::function<void()>& func):
    //m_func(std::move(func)) {
    m_func(func){
    //IManager::IManager();
    std::chrono::duration<double> timeSeconds(0.1);// = std::chrono::duration<std::chrono::seconds>(updateTime);
    //std::chrono::seconds timeSeconds(updateTime);
    m_updateTime = std::chrono::duration_cast<std::chrono::milliseconds>(timeSeconds).count();
    //m_updateTime = timeSeconds;
    isExit = false;
    m_thread = std::thread(&Manager::updater, this);
}
Manager::~Manager() {
    isExit = true;
    if (m_thread.joinable()) {
        m_thread.join();
    }
    std::cout << "Manager Destroyed" << std::endl;
}
void Manager::sayHello() {
    std::cout << "Hello Manager" << std::endl;
}
void Manager::updater() {
    while (!isExit) {
        std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();

        m_func();

        while (true) {
            std::chrono::system_clock::time_point t2 = std::chrono::system_clock::now();
            auto t = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
            if (t >= m_updateTime) {
                break;
            } else {
                std::this_thread::sleep_for(200ms);
            }
        }
    }
}

