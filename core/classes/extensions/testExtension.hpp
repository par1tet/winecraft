#include<classes/extensions/extension.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<string.h>
#include<GLFW/glfw3.h>

#ifndef testExtension
#define testExtension

class TestExtension : public Extension {
public:
    TestExtension() : Extension() {
    }

    void gameFrame(WorldKeeper* worldKeeperCl, int enId);
    void gameInit(GLFWwindow* window);
    virtual std::string getExName(){return "TestExtension";}
};


#endif