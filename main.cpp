#include <iostream>
#include <memory>
#include <deque>
#include <functional>

#include "GreecePier.h"
#include "ShipGenerator.h"
#include "IShip.h"
#include "StateMachine.h"
#include "IManager.h"
#include "Manager.h"
#include "TQueue.h"
#include "SigHandler.h"
#include "SHandler.h"


class H {
public:
    H(): mK(10) {
        std::cout << "default constructor called" << std::endl;
    }
    H(int k) : mK(k) {
        std::cout << "parameter constructor called" << std::endl;
    }

    inline int get() const {
        return mK;
    }

private:
    int mK;
};

void exampleFunction() {
    std::cout << "hi" << std::endl;
    //Ship* sh = new Ship();
    std::deque <std::unique_ptr<IShip>> q;
    auto shipGenerator = ShipGenerator::getInstance();
    // auto ship = shipGenerator->createRandomShip();
    // ship->sayHello();
    for (int i = 0; i < 10; i++) {
        q.push_back(shipGenerator->createRandomShip());
    }
    for (const auto& p : q) {
        // q.front()->sayHello();
        q.pop_front();
    }

    std::unique_ptr<StateMachine> machine = std::make_unique<StateMachine>();
    machine->setState(State::INIT);
    //std::function<void ()> func = std::bind(exampleFunction);

    //std::unique_ptr<IManager> mgr = std::make_unique<Manager>([=]() {exampleFunction();});
    //std::unique_ptr<IManager> mgr = std::make_unique<Manager>(func);
    //mgr->sayHello();

    //auto qu = std::make_unique<TQueue<std::string>>();
    //TQueue<int>* qu = new TQueue<int>();
    std::unique_ptr<TQueue<int>> qu = std::make_unique<TQueue<int>>();
    //auto qu = std::make_unique<TQueue<std::string>>();
    // std::cout << n << std::endl;
    //auto sHandler = SHandler();

    // auto handler = SigHandler::getInstance();
    // auto sig = handler->waitSignal();
}

void workFunction() {
    std::unique_ptr<GreecePier> greecePier = std::make_unique<GreecePier>();
    greecePier->start();
}

void myFunc();

int main() {
        std::unique_ptr<GreecePier> greecePier = std::make_unique<GreecePier>();
        greecePier->start();
        auto handler = SigHandler::getInstance();
        auto sig = handler->waitSignal();
        std::cout << "SIGINT " << sig << std::endl;
        // if (t->joinable()) {
        //     t->join();
        //     std::cout << "t joined" << std::endl;
        // }

        // if (t2->joinable()) {
        //     t2->join();
        //     std::cout << "t2 joined" << std::endl;
        // }
        
    return 0;
}