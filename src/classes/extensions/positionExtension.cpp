#include <GLFW/glfw3.h>
#include<classes/extensions/positionExtension.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include <iostream>
#include <ostream>
#include<stdio.h>
#include<string>
#include<glm/glm.hpp>
#include<map>
#include <vector>

Acceleration::Acceleration(glm::vec3 acceleration, float startTime){
    this->acceleration = acceleration;
    this->startTime = startTime;
}

glm::vec3 Acceleration::getAcceleration(){
    return acceleration;
}

float Acceleration::getStartTime(){
    return startTime;
}

void Acceleration::setStartTime(float newStartTime){
    startTime = newStartTime;
}

void Acceleration::setIsActive(bool newIsActive){
    isActive = newIsActive;
}

bool Acceleration::getIsActive(){
    return isActive;
}

Position::Position(glm::vec3 position) : Extension(){
    this->position = position;
}

void Position::gameFrame(WorldKeeper* worldKeeperCl, int enId){
    std::vector<std::string> thisAccelerationNames = this->getAccelerationsNames();
    std::cout << thisAccelerationNames.size() << std::endl;
    for(int i = 0;i != thisAccelerationNames.size();i++){
        if(this->getAccelerations()[thisAccelerationNames[i]]->getIsActive()){
            float deltaTime = glfwGetTime() - this->getAccelerations()[thisAccelerationNames[i]]->getStartTime();

            std::cout << deltaTime << std::endl;

            this->setVelocity(this->getVelocity() + (this->getAccelerations()[thisAccelerationNames[i]]->getAcceleration() * deltaTime));
        }
    }

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
