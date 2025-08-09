#include<classes/worldKeeper/triggers/keyTrigger.hpp>
#include<glm/glm.hpp>
#include<functional>
#include<iostream>
#include<GLFW/glfw3.h>

KeyTrigger::KeyTrigger(){
}

void KeyTrigger::handleKey(int key, int scancode, int action, int mode){
    if (action == GLFW_PRESS) {
        this->keys[key] = true;
    } else if (action == GLFW_RELEASE) {
        this->keys[key] = false;
    }
}

bool* KeyTrigger::getKeys(){
    return keys;
}