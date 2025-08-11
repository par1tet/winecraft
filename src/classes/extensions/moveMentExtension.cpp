#include<classes/extensions/moveMentExtension.hpp>
#include<classes/entities/entity.hpp>
#include<classes/extensions/positionExtension.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include <glm/geometric.hpp>
#include <iostream>
#include <ostream>
#include<stdio.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<string>
#include<map>

MoveMent::MoveMent(float maxSpeed, double runUpTime, std::vector<KeyMove> keyMoves) : Extension(){
	this->maxSpeed = maxSpeed;
	this->runUpTime = runUpTime;
    this->keyMoves = keyMoves;
    this->invertMove = false;
}

MoveMent::MoveMent(float maxSpeed, double runUpTime, std::vector<KeyMove> keyMoves, bool invertMove) : Extension(){
	this->maxSpeed = maxSpeed;
	this->runUpTime = runUpTime;
    this->keyMoves = keyMoves;
    this->invertMove = invertMove;
}

void MoveMent::gameInit(GLFWwindow* window){}
std::string MoveMent::getExName(){return "MoveMentExtension";}

void moveDir(Position* positionEntity, bool* keysTrigger, KeyMove keyMove, float runUpTime, bool invertMove){
    string keyMoveString = std::string({keyMove.key}); 

    std::cout << keyMoveString << std::endl;
    std::cout << keysTrigger[(int)keyMove.key] << std::endl;

    float invertCooficient = 1.f;

    if(invertMove) invertCooficient = -1.f;

    if(keysTrigger[(int)keyMove.key]){
        if(positionEntity->getAccelerations().count(keyMoveString) > 0){
            if(!positionEntity->getAccelerations()[keyMoveString]->getIsActive()){
                positionEntity->getAccelerations()[keyMoveString]->setIsActive(true);
            }

            positionEntity->getAccelerations()[keyMoveString]->setAcceleration(invertCooficient * runUpTime * keyMove.direct);
        }else{
            positionEntity->generateNewAcceleration(new Acceleration(invertCooficient * runUpTime * keyMove.direct), keyMoveString);
        }

    }else{
        if(positionEntity->getAccelerations().count(keyMoveString) > 0){
            positionEntity->getAccelerations()[keyMoveString]->setIsActive(false);
        }
    }
}

void MoveMent::gameFrame(float dTime, WorldKeeper* worldKeeperCl, int enId){
    Entity* thisEntity = (worldKeeperCl->getEntities()[enId]);

	bool* keysTrigger = worldKeeperCl->getTriggerManager()->getKeyTrigger()->getKeys();

    std::cout << "ID: " << enId << std::endl;
    std::cout << "moveSeg" << std::endl;
    std::cout << thisEntity << std::endl;
    Position* positionEntity = (thisEntity)->getExtension<Position>("PositionExtension");

    std::cout << positionEntity->getPosition().x << std::endl;

    for(int i = 0;i != this->keyMoves.size();i++){
        moveDir(positionEntity, keysTrigger, this->keyMoves[i], this->runUpTime, this->invertMove);
    }

    if(glm::length(positionEntity->getVelocity()) > sqrt(this->maxSpeed*this->maxSpeed)){
        positionEntity->setVelocity(glm::normalize(positionEntity->getVelocity()) * this->maxSpeed);
    }
}

std::vector<KeyMove> MoveMent::getKeyMoves(){
    return this->keyMoves;
}

void MoveMent::setKeyMoves(std::vector<KeyMove> newKeyMoves){
    std::cout << "sosaaaaaaaal" << std::endl;
    this->keyMoves = newKeyMoves;
}