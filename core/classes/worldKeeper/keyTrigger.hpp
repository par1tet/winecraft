#include<GLFW/glfw3.h>
#include<vector>

#pragma once

class KeyTrigger {
private:
    GLFWwindow* window;
    bool keys[348] = {false};

public:
    KeyTrigger(GLFWwindow* window);

    static void callbackFunction(GLFWwindow *window, int key, int scancode, int action, int mode);

    bool* getKeys();
};