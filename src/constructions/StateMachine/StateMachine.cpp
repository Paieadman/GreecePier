#include <iostream>

#include "StateMachine.h"
#include "Specification.h"

StateMachine::~StateMachine() {
    std::cout << __func__ << std::endl;
}

StateMachine::StateMachine() {
    std::cout << __func__ << std::endl;
}

void StateMachine::setState(State state){
    std::cout << "setState" << std::endl;
    //std::cout << __func__ << std::endl;
}

void StateMachine::setStateInit(){

}

void StateMachine::setStateRun(){

}

void StateMachine::setStateStop(){

}