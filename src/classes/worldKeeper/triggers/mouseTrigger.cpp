#include<classes/worldKeeper/triggers/mouseTrigger.hpp>
#include<iostream>

MouseTrigger::MouseTrigger(){
}

void MouseTrigger::handleMouse(double xpos, double ypos){
    this->positionMouse = {xpos, ypos};    
}

PositionMouse MouseTrigger::getPositionMouse(){
    return this->positionMouse;
}