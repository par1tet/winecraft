#pragma once

#include<classes/extensions/extension.hpp>
#include<classes/entities/entity.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<string.h>
#include<glm/glm.hpp>
#include<map>
#include<vector>

#define DIR_LEFT glm::vec3{-1.f, 0.f, 0.f}
#define DIR_RIGHT glm::vec3{1.f, 0.f, 0.f}
#define DIR_FORWARD glm::vec3{0.f, 0.f, 1.f}
#define DIR_BACK glm::vec3{0.f, 0.f, -1.f}
#define DIR_UP glm::vec3{0.f, 1.f, 0.f}
#define DIR_DOWN glm::vec3{0.f, -1.f, 0.f}

struct KeyMove {
    glm::vec3 direct;
    char key;
};

class MoveMent : public Extension {
private:
    float maxSpeed;
    double runUpTime;
    std::vector<KeyMove> keyMoves;
    bool invertMove;

public:
    MoveMent(float maxSpeed, double runUpTime, std::vector<KeyMove> keyMoves);
    MoveMent(float maxSpeed, double runUpTime, std::vector<KeyMove> keyMoves, bool invertMove);

    void gameInit(GLFWwindow* window);
    void gameFrame(float dTime, WorldKeeper* worldKeeperCl, int enId);
    std::string getExName();
    std::vector<KeyMove> getKeyMoves();
    void setKeyMoves(std::vector<KeyMove> newKeyMoves);
};
