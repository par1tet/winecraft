#include<classes/extensions/position.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<stdio.h>
#include<string>
#include<glm/glm.hpp>

Position::Position(glm::vec3 position) : Extension(){
    this->position = position;
}

void Position::gameFrame(WorldKeeper* worldKeeperCl, int enId){
    std::cout << "x: " << this->position.x << " y: " << this->position.y << " z: " << this->position.z << std::endl;
}

std::string Position::getExName(){
    return "Position";
}

glm::vec3 Position::getPosition(){
    return position;
}

void Position::setPosition(glm::vec3 newPosition){
    position = newPosition;
}

void Position::changePosition(glm::vec3 dPosition){
    setPosition(position + dPosition);
}