#include <classes/worldKeeper/worldKeeper.hpp>
#include <classes/extensions/extension.hpp>
#include <stdio.h>
#include <string>
#include <vector>
#include <GLFW/glfw3.h>

WorldKeeper::WorldKeeper(std::vector<Entity*> entities, GLFWwindow* window, KeyTrigger* keyTrigger){
    this->entities = entities;
    this->window = window;
    this->keyTrigger = keyTrigger;

    for(int i = 0;i != this->entities.size();i++){
        this->entities[i]->gameInit(window);
    }
}

void WorldKeeper::gameFrame(){
    system("clear");

    std::vector<std::string> extensionQueue = {
        "ObjectExtension", "MoveMentExtension",
        "CollisionExtension", "PositionExtension"
    };

    for(int j = 0;j != extensionQueue.size();j++){
        for(int i = 0;i != this->entities.size();i++){
            if(this->entities[i]->getExtensions().find(extensionQueue[j]) != this->entities[i]->getExtensions().end()){
                this->entities[i]->getExtensions()[extensionQueue[j]]->gameFrame(this, i);
            }
        }
    }
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
