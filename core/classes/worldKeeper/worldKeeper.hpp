#pragma once

#include<vector>
#include<classes/worldKeeper/keyTrigger.hpp>
#include<iostream>
#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>
#include<classes/entities/camera/camera.hpp>

class WorldKeeper{
private:
    std::vector<Entity*> entities;
    GLFWwindow* window;
    KeyTrigger* keyTrigger;
    Camera* camera;

public:
    WorldKeeper(std::vector<Entity*> entities, GLFWwindow* window, KeyTrigger* keyTrigger, Camera* camera);

    void gameFrame(float dTime);
    KeyTrigger* getKeyTrigger();
    std::vector<Entity*> getEntities();
    GLFWwindow* getWindow();
    Camera* getCamera();
};
