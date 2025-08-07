#include<classes/extensions/moveMentExtension.hpp>
#include<classes/entities/entity.hpp>
#include<classes/extensions/positionExtension.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<classes/worldKeeper/keyTrigger.hpp>
#include <glm/geometric.hpp>
#include <iostream>
#include <ostream>
#include<stdio.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<string>
#include<map>
#include<string>

MoveMent::MoveMent(float maxSpeed, double runUpTime, std::vector<KeyMove> keyMoves) : Extension(){
	this->maxSpeed = maxSpeed;
	this->runUpTime = runUpTime;
    this->keyMoves = keyMoves;
}

void MoveMent::gameInit(GLFWwindow* window){}
std::string MoveMent::getExName(){return "MoveMentExtension";}

glm::vec3 transformationDirect(Direction dir){
    switch (dir)
    {
        case Direction::LEFT:
            return glm::vec3(-1.f, 0.f, 0.f);
            break;
        case Direction::RIGHT:
            return glm::vec3(1.f, 0.f, 0.f);
            break;
        case Direction::UP:
            return glm::vec3(0.f, 1.f, 0.f);
            break;
        case Direction::DOWN:
            return glm::vec3(0.f, -1.f, 0.f);
            break;
        case Direction::BACK:
            return glm::vec3(0.f, 0.f, -1.f);
            break;
        case Direction::FORWARD:
            return glm::vec3(0.f, 0.f, 1.f);
            break;
    }

    return glm::vec3{0.f};
}

void moveDir(Position* positionEntity, bool* keysTrigger, KeyMove keyMove, float runUpTime){
    string keyMoveString = std::string({keyMove.key}); 

    std::cout << keyMoveString << std::endl;
    std::cout << keysTrigger[(int)keyMove.key] << std::endl;

    if(keysTrigger[(int)keyMove.key]){
        if(positionEntity->getAccelerations().count(keyMoveString) > 0){
            if(!positionEntity->getAccelerations()[keyMoveString]->getIsActive()){
                positionEntity->getAccelerations()[keyMoveString]->setIsActive(true);
            }
        }else{
            positionEntity->generateNewAcceleration(new Acceleration(runUpTime * transformationDirect(keyMove.direct)), keyMoveString);
        }

    }else{
        if(positionEntity->getAccelerations().count(keyMoveString) > 0){
            positionEntity->getAccelerations()[keyMoveString]->setIsActive(false);
        }
    }
}

void MoveMent::gameFrame(float dTime, WorldKeeper* worldKeeperCl, int enId){
    Entity* thisEntity = (worldKeeperCl->getEntities()[enId]);

	bool* keysTrigger = worldKeeperCl->getKeyTrigger()->getKeys();

    std::cout << "ID: " << enId << std::endl;
    std::cout << "moveSeg" << std::endl;
    std::cout << thisEntity << std::endl;
    Position* positionEntity = (thisEntity)->getExtension<Position>("PositionExtension");

    std::cout << positionEntity->getPosition().x << std::endl;

    for(int i = 0;i != this->keyMoves.size();i++){
        moveDir(positionEntity, keysTrigger, keyMoves[i], this->runUpTime);
    }

    if(glm::length(positionEntity->getVelocity()) > sqrt(this->maxSpeed*this->maxSpeed)){
        positionEntity->setVelocity(glm::normalize(positionEntity->getVelocity()) * this->maxSpeed);
    }
}
