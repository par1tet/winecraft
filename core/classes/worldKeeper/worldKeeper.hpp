#include<classes/entities/entity.hpp>
#include<GLFW/glfw3.h>
#include<vector>
#include<classes/worldKeeper/keyTrigger.hpp>
#include<iostream>

#ifndef worldKeeper
#define worldKeeper

class WorldKeeper{
public:
    WorldKeeper(std::vector<Entity*> entities, GLFWwindow* window, KeyTrigger* keyTrigger){

        this->entities = entities;
        this->window = window;
        this->keyTrigger = keyTrigger;

        for(int i = 0;i != this->entities.size();i++){
            this->entities[i]->gameInit(window);
        }
    }

    void gameFrame();
    KeyTrigger* getKeyTrigger(){
        return this->keyTrigger;
    }


    std::vector<Entity*> entities;
    GLFWwindow* window;
    KeyTrigger* keyTrigger;
};

#endif