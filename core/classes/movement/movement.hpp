#include<classes/extensions/extension.hpp>
#include<GLFW/glfw3.h>

#ifndef entityclass
#define entityclass

class Movement : public Extension {
public:
    Movement(){
        
    }

    logicFrame(GLFWwindow window);

private:
    string name = 'Movement';
}

#endif