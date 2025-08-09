#include <classes/worldKeeper/worldKeeper.hpp>
#include <classes/extensions/extension.hpp>
#include <stdio.h>
#include <string>
#include <vector>
#include <GLFW/glfw3.h>

WorldKeeper::WorldKeeper(std::vector<Entity*> entities, GLFWwindow* window, KeyTrigger* keyTrigger, Camera* camera){
    this->entities = entities;
    this->window = window;
    this->keyTrigger = keyTrigger;
    this->camera = camera;

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

Camera* WorldKeeper::getCamera(){
    return this->camera;
}

std::vector<Entity*> WorldKeeper::getEntities(){
    return entities;
}

GLFWwindow* WorldKeeper::getWindow(){
    return window;
}

KeyTrigger* WorldKeeper::getKeyTrigger(){
    return keyTrigger;
}
