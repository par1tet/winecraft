#pragma once

#include<vector>
#include<glad/glad.h>
#include<classes/worldKeeper/triggers/triggerManager.hpp>
#include<iostream>
#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>
#include<classes/entities/camera/camera.hpp>

class WorldKeeper{
private:
    std::vector<Entity*> entities;
    GLFWwindow* window;
    TriggerManager* triggerManager;
    Camera* camera;

public:
    WorldKeeper(std::vector<Entity*> entities, GLFWwindow* window, Camera* camera);

    void gameFrame(float dTime);
    TriggerManager* getTriggerManager();
    std::vector<Entity*> getEntities();
    GLFWwindow* getWindow();
    Camera* getCamera();
};
