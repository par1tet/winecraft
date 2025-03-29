#include<classes/entities/entity.hpp>
#include<GLFW/glfw3.h>
#include<vector>

#ifndef worldKeeper
#define worldKeeper

class WorldKeeper{
public:
    // Init WorldKeeper
    WorldKeeper(std::vector<Entity*> entities, GLFWwindow* window){
        this->entities = entities;
        this->window = window;
    }

    void gameFrame();
    // std::vector<Entity*> getEntities();

    std::vector<Entity*> entities;
    GLFWwindow* window;
};

#endif