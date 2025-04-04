#include<classes/extensions/positionExtension.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<stdio.h>
#include<string>
#include<glm/glm.hpp>

Position::Position(glm::vec3 position) : Extension(){
    this->position = position;
}

void Position::gameFrame(WorldKeeper* worldKeeperCl, int enId){
    this->changePosition(this->getVelocity());
    std::cout << "x: " << this->getPosition().x << " y: " << this->getPosition().y << std::endl;
}

std::string Position::getExName(){
    return "PositionExtension";
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

void Position::setVelocity(glm::vec3 newVelocity){
    velocity = newVelocity;
}

void Position::setVelocityY(float y){
    velocity.y = y;
}

void Position::setVelocityX(float x){
    velocity.x = x;
}

void Position::setVelocityZ(float z){
    velocity.z = z;
}

glm::vec3 Position::getVelocity(){
    return velocity;
}
