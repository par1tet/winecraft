#include <classes/worldKeeper/worldKeeper.hpp>
#include <classes/extensions/extension.hpp>
#include <stdio.h>
#include <string>
#include <vector>
#include <GLFW/glfw3.h>

WorldKeeper::WorldKeeper(std::vector<Entity*> entities, std::map<std::string, SpecialEntity*> specialList, GLFWwindow* window){
    this->entities = entities;
    this->window = window;
    this->triggerManager = new TriggerManager(window);

    for(int i = 0;i != this->entities.size();i++){
        this->entities[i]->gameInit(window);
    }
}

void WorldKeeper::gameFrame(float dTime){
    std::vector<std::string> extensionQueue = {
        "PhysicsExtension", "ObjectExtension", "MoveMentExtension", 
        "CollisionExtension", "PositionExtension", "RotateCameraExtension"
    };

    for(int j = 0;j != extensionQueue.size();j++){
        for(int i = 0;i != this->entities.size();i++){
            if(this->entities[i]->getExtensions().find(extensionQueue[j]) != this->entities[i]->getExtensions().end()){
                this->entities[i]->getExtensions()[extensionQueue[j]]->gameFrame(dTime, this, i);
            }
        }
    }
}

SpecialEntity* WorldKeeper::getSpecialEntity(std::string specialName){
    return this->specialList[specialName];
}

std::vector<Entity*> WorldKeeper::getEntities(){
    return entities;
}

GLFWwindow* WorldKeeper::getWindow(){
    return window;
}

TriggerManager* WorldKeeper::getTriggerManager(){
    return this->triggerManager;
}
