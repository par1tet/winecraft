#include<classes/extensions/extension.hpp>
#include<classes/entities/entity.hpp>
#include<glm/glm.hpp>

#pragma once

class Position : public Extension {
private:
    glm::vec3 position;
    glm::vec3 velocity = glm::vec3{0.0f};

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
};
