#pragma once
#include <thread>
#include <functional>

class IManager {
public:
    //IManager();
    //IManager(std::function<void()>& func);
    virtual ~IManager() = default;
    virtual void sayHello() = 0;
};