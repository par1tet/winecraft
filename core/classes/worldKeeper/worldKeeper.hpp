#include<classes/entities/entity.hpp>
#include<GLFW/glfw3.h>
#include<vector>
#include<classes/worldKeeper/keyTrigger.hpp>
#include<iostream>

#pragma once

class WorldKeeper{
private:
    std::vector<Entity*> entities;
    GLFWwindow* window;
    KeyTrigger* keyTrigger;

public:
    WorldKeeper(std::vector<Entity*> entities, GLFWwindow* window, KeyTrigger* keyTrigger);

    void gameFrame();
    KeyTrigger* getKeyTrigger();
    std::vector<Entity*> getEntities();
    GLFWwindow* getWindow();
};