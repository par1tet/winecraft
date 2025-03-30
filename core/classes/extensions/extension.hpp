#include<string>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<GLFW/glfw3.h>

#ifndef extension
#define extension

class Entity;

class Extension{
public:
    Extension(){
    }

    virtual void gameFrame(WorldKeeper* worldKeeperCl, int enId);
    virtual void gameInit(GLFWwindow* window);
    virtual std::string getExName(){return "Extension";}
};

#endif