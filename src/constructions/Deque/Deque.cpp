#include <mutex>
#include <memory>
#include <deque>

#include "Deque.h"
#include "Ship.h"

Deque::Deque() {

}

Deque::~Deque() {

}

void Deque::pushElement(std::unique_ptr<Ship> ship) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_deque->push_back(std::move(ship));
    lock.unlock();
}

std::unique_ptr<Ship> Deque::popElement() {
    std::unique_lock<std::mutex> lock(m_mutex);
    std::unique_ptr<Ship> ptr = std::move(m_deque->front());
    m_deque->pop_front();
    lock.unlock();
    return ptr;
}