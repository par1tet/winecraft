#include<classes/extensions/positionExtension.hpp>
#include <iostream>
#include <ostream>
#include<stdio.h>
#include<string>
#include<glm/glm.hpp>
#include<map>
#include <vector>

Acceleration::Acceleration(glm::vec3 acceleration){
    this->acceleration = acceleration;
}

glm::vec3 Acceleration::getAcceleration(){
    return acceleration;
}

void Acceleration::setIsActive(bool newIsActive){
    isActive = newIsActive;
}

bool Acceleration::getIsActive(){
    return isActive;
}

void Acceleration::setAcceleration(glm::vec3 newAcceleration){
    this->acceleration = newAcceleration;
}

Position::Position(glm::vec3 position) : Extension(){
    this->position = position;
    this->linkedEntity.idEntity = -1;
}

void Position::gameFrame(float dTime, WorldKeeper* worldKeeperCl, int enId){
    if(this->linkedEntity.idEntity == -1){
        std::vector<std::string> thisAccelerationNames = this->getAccelerationsNames();

        this->setVelocity(this->getVelocity() + (this->getFullAcceleration(dTime) * dTime));

        this->changePosition(this->getVelocity() * dTime);

        std::cout << "x: " << this->getPosition().x << " y: " << this->getPosition().y << std::endl;
    }else{
        Position* linkedPosition = worldKeeperCl->getEntities()[this->linkedEntity.idEntity]->getExtension<Position>("PositionExtension");

        std::cout << "chilen" << std::endl;

        if(linkedEntity.typeOfLink == typeLink::additional){
            float invertCoff = 1;
            if(linkedEntity.invertMove){invertCoff = -1;}
            this->setPosition(this->linkedEntity.originPosition + invertCoff*linkedPosition->getPosition());
        }else if(linkedEntity.typeOfLink == typeLink::equalitional){
            float invertCoff = 1;
            if(linkedEntity.invertMove){invertCoff = -1;}
            this->setPosition(invertCoff*linkedPosition->getPosition());
        }
    }
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
    this->velocity.y = y;
}
 
void Position::setVelocityX(float x){
    this->velocity.x = x;
}

void Position::setVelocityZ(float z){
    this->velocity.z = z;
}

glm::vec3 Position::getVelocity(){
    return this->velocity;
}

std::map<std::string, Acceleration*> Position::getAccelerations(){
    return accelerations;
}

int Position::generateNewAcceleration(Acceleration* acceleration, std::string name){
    this->accelerations[name] = acceleration;
    this->accelerationsNames.push_back(name);

    return accelerations.size() - 1;
}

std::vector<std::string> Position::getAccelerationsNames(){
    return accelerationsNames;
}

void Position::setAccelerations(std::map<std::string, Acceleration*> newAcc, std::vector<std::string> newNames){
    this->accelerations = newAcc;
    this->accelerationsNames = newNames;
}

glm::vec3 Position::getFullAcceleration(float dTime){
    std::vector<std::string> thisAccelerationNames = this->getAccelerationsNames();
    glm::vec3 fullAcceleration = glm::vec3{0.f};

    for(int i = 0;i != thisAccelerationNames.size();i++){
        if(this->getAccelerations()[thisAccelerationNames[i]]->getIsActive()){
            fullAcceleration += this->getAccelerations()[thisAccelerationNames[i]]->getAcceleration();
        }
    }

    return fullAcceleration;
}

glm::vec3 Position::getFullVelocity(float dTime){
    return this->getVelocity() + (getFullAcceleration(dTime) * dTime);
}

void Position::linkEntity(linked linkedEn){
    this->linkedEntity = linkedEn;
}