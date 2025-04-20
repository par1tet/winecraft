#include<string>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<GLFW/glfw3.h>

#pragma once

class Entity;

class Extension{
public:
    virtual ~Extension() = default;
    Extension(){

    }

    virtual void gameFrame(float dTime, WorldKeeper* worldKeeperCl, int enId);
    virtual void gameInit(GLFWwindow* window);
    virtual std::string getExName(){return "Extension";}
};
