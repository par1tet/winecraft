#include<classes/extensions/extension.hpp>
#include<classes/entities/entity.hpp>
#include<glm/glm.hpp>
#include<map>
#include <vector>

#pragma once

class Acceleration {
private:
    glm::vec3 acceleration;
    float startTime;
    bool isActive;

public:
    Acceleration(glm::vec3 acceleration, float startTime);
    
    void setStartTime(float);
    glm::vec3 getAcceleration();
    float getStartTime();
    void setIsActive(bool);
    bool getIsActive();
    void setAcceleration(glm::vec3 newAcceleration);
};

class Position : public Extension {
private:
    glm::vec3 position;
    glm::vec3 velocity = glm::vec3{0.0f};
    std::map<std::string, Acceleration*> accelerations;
    std::vector<std::string> accelerationsNames;

public:
    Position(glm::vec3 position);

    void gameFrame(WorldKeeper* worldKeeperCl, int enId);
    std::string getExName();

    glm::vec3 getPosition();
    void setPosition(glm::vec3 newPosition);
    void changePosition(glm::vec3 dPosition);
    glm::vec3 getVelocity();
    void setVelocity(glm::vec3 newVelocity);
    void setVelocityY(float);
    void setVelocityX(float);
    void setVelocityZ(float);
    std::map<std::string, Acceleration*> getAccelerations();
    int generateNewAcceleration(Acceleration*, std::string);
    std::vector<std::string> getAccelerationsNames();
};
