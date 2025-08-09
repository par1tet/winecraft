#include<classes/worldKeeper/triggers/triggerManager.hpp>

TriggerManager::TriggerManager(GLFWwindow* window){
    this->window = window;
    this->keyTrigger = new KeyTrigger();
    this->mouseTrigger = new MouseTrigger();

    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, this->keyCallback);
    glfwSetCursorPosCallback(window, this->mouseCallback);
}

void TriggerManager::handleKey(int key, int scancode, int action, int mods) {
    this->keyTrigger->handleKey(key, scancode, action, mods);
}

void TriggerManager::handleMouse(double xpos, double ypos) {
    this->mouseTrigger->handleMouse(xpos, ypos);
}

void TriggerManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    auto* manager = static_cast<TriggerManager*>(glfwGetWindowUserPointer(window));
    if (manager) {
        manager->handleKey(key, scancode, action, mods);
    }
}

void TriggerManager::mouseCallback(GLFWwindow* window, double xpos, double ypos) {
    auto* manager = static_cast<TriggerManager*>(glfwGetWindowUserPointer(window));
    if (manager) {
        manager->handleMouse(xpos, ypos);
    }
}

KeyTrigger* TriggerManager::getKeyTrigger(){
    return this->keyTrigger;
}

MouseTrigger* TriggerManager::getMouseTrigger(){
    return this->mouseTrigger;
}