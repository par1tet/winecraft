#pragma once

#include<vector>
#include<glad/glad.h>
#include<classes/worldKeeper/triggers/triggerManager.hpp>
#include<iostream>
#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>
#include<classes/entities/specialEntities/specialEntity.hpp>
#include<map>

class WorldKeeper{
private:
    std::vector<Entity*> entities;
    GLFWwindow* window;
    TriggerManager* triggerManager;
	std::map<std::string, SpecialEntity*> specialList;

public:
    WorldKeeper(std::vector<Entity*> entities, std::map<std::string, SpecialEntity*> specialList, GLFWwindow* window);

    void gameFrame(float dTime);
    TriggerManager* getTriggerManager();
    std::vector<Entity*> getEntities();
    GLFWwindow* getWindow();
    SpecialEntity* getSpecialEntity(std::string);
};
