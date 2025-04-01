#include<GLFW/glfw3.h>
#include<vector>

#ifndef keyTriggerclass
#define keyTriggerclass

class KeyTrigger {
public:
    KeyTrigger(GLFWwindow* window);

    static void callbackFunction(GLFWwindow *window, int key, int scancode, int action, int mode);

    GLFWwindow* window;
    bool keys[348] = {false};
};

#endif