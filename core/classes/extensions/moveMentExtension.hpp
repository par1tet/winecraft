#include<classes/extensions/extension.hpp>
#include<classes/entities/entity.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<string.h>
#include<glm/glm.hpp>
#include<map>

#pragma once

class MoveMent : public Extension {
private:
    float maxSpeed;
    double runUpTime;

public:
    MoveMent(float maxSpeed, double runUpTime);

    void gameInit(GLFWwindow* window);
    void gameFrame(float dTime, WorldKeeper* worldKeeperCl, int enId);
    std::string getExName();
};
