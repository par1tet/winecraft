#include<classes/extensions/extension.hpp>
#include<classes/entities/entity.hpp>
#include<string.h>
#include<glm/glm.hpp>

#pragma once

class Position : public Extension {
private:
    glm::vec3 position;
public:
    Position(glm::vec3 position);

    void gameFrame(WorldKeeper* worldKeeperCl, int enId);
    std::string getExName();

    glm::vec3 getPosition();
    void setPosition(glm::vec3 newPosition);
    void changePosition(glm::vec3 dPosition);
};