#pragma once

#include <memory>
#include <deque>
#include <mutex>
#include <atomic>

#include "Ship.h"

class Deque {
protected:
    std::mutex m_mutex;
    std::unique_ptr<std::deque<std::unique_ptr<Ship>>> m_deque;
public:
    Deque();
    virtual ~Deque();
    virtual void pushElement(std::unique_ptr<Ship>);
    virtual std::unique_ptr<Ship> popElement();
};