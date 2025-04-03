#include <classes/worldKeeper/worldKeeper.hpp>
#include <classes/extensions/extension.hpp>
#include <stdio.h>
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

    for(int i = 0;i != this->entities.size();i++){
        for(int j = 0;j != this->entities[i]->getExtensionsNames().size();j++){
            this->entities[i]->getExtensions()[(this->entities[i])->getExtensionsNames()[j]]->gameFrame(this, i);
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
