#include<classes/worldKeeper/keyTrigger.hpp>
#include<glm/glm.hpp>
#include<functional>
#include<GLFW/glfw3.h>
#include<iostream>

KeyTrigger::KeyTrigger(GLFWwindow* window){
    this->window = window;
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(this->window, this->callbackFunction);
}

void KeyTrigger::callbackFunction(GLFWwindow *window, int key, int scancode, int action, int mode){
    KeyTrigger* contextThis = static_cast<KeyTrigger*>(glfwGetWindowUserPointer(window));
    // std::cout << contextThis->keys[key] << std::endl; 
    if (action == GLFW_PRESS) {
        contextThis->keys[key] = true;
    } else if (action == GLFW_RELEASE) {
        contextThis->keys[key] = false;
    }
}