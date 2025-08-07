#pragma once

#include<classes/extensions/extension.hpp>
#include<classes/entities/entity.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<string.h>
#include<glm/glm.hpp>
#include<map>
#include<vector>

enum class Direction {
    LEFT,
    RIGHT,
    DOWN,
    UP,
    BACK,
    FORWARD,
};

struct KeyMove {
    Direction direct;
    char key;
};

class MoveMent : public Extension {
private:
    float maxSpeed;
    double runUpTime;
    std::vector<KeyMove> keyMoves;

public:
    MoveMent(float maxSpeed, double runUpTime, std::vector<KeyMove> keyMoves);

    void gameInit(GLFWwindow* window);
    void gameFrame(float dTime, WorldKeeper* worldKeeperCl, int enId);
    std::string getExName();
};
