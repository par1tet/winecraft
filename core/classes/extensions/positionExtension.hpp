#pragma once

#include<classes/entities/entity.hpp>
#include<classes/extensions/extension.hpp>
#include<glm/glm.hpp>
#include<map>
#include <vector>

enum typeLink {
    additional,
    equalitional
};

struct linked {
    int idEntity;
    bool invertMove;
    typeLink typeOfLink;
    glm::vec3 originPosition = glm::vec3{0.f};
};

class Acceleration {
private:
    glm::vec3 acceleration;
    bool isActive;

public:
    Acceleration(glm::vec3 acceleration);
    
    glm::vec3 getAcceleration();
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
    linked linkedEntity;

public:
    Position(glm::vec3 position);

    void gameFrame(float dTime, WorldKeeper* worldKeeperCl, int enId);
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
    void setAccelerations(std::map<std::string, Acceleration*> newAcc, std::vector<std::string> newNames);
    glm::vec3 getFullAcceleration(float dTime);
    glm::vec3 getFullVelocity(float dTime);
    void linkEntity(linked linkedEn);
};
