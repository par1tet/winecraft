#pragma once

#include<classes/entities/entity.hpp>
#include<vector>
#include<classes/worldKeeper/keyTrigger.hpp>
#include<iostream>
#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>

class WorldKeeper{
private:
    std::vector<Entity*> entities;
    GLFWwindow* window;
    KeyTrigger* keyTrigger;

public:
    WorldKeeper(std::vector<Entity*> entities, GLFWwindow* window, KeyTrigger* keyTrigger);

    void gameFrame(float dTime);
    KeyTrigger* getKeyTrigger();
    std::vector<Entity*> getEntities();
    GLFWwindow* getWindow();
};
