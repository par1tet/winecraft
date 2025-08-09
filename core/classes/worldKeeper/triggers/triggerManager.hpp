#pragma once

#include<GLFW/glfw3.h>
#include<classes/worldKeeper/triggers/keyTrigger.hpp>
#include<classes/worldKeeper/triggers/mouseTrigger.hpp>

class TriggerManager {
private:
    GLFWwindow* window;
    KeyTrigger* keyTrigger;
    MouseTrigger* mouseTrigger;

public:
    TriggerManager(GLFWwindow* window);

    void handleKey(int key, int scancode, int action, int mods);
    void handleMouse(double xpos, double ypos);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouseCallback(GLFWwindow* window, double xpos, double ypos);
    KeyTrigger* getKeyTrigger();
    MouseTrigger* getMouseTrigger();
};