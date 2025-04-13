#include<classes/extensions/moveMentExtension.hpp>
#include<classes/entities/entity.hpp>
#include<classes/extensions/positionExtension.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<classes/worldKeeper/keyTrigger.hpp>
#include <iostream>
#include <ostream>
#include<stdio.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<string>
#include<map>

MoveMent::MoveMent(double maxSpeed, double runUpTime) : Extension(){
	this->maxSpeed = maxSpeed;
	this->runUpTime = runUpTime;
}

void MoveMent::gameInit(GLFWwindow* window){}
std::string MoveMent::getExName(){return "MoveMentExtension";}

void MoveMent::gameFrame(WorldKeeper* worldKeeperCl, int enId){
    Entity* thisEntity = worldKeeperCl->getEntities()[enId];

	bool* keysTrigger = worldKeeperCl->getKeyTrigger()->getKeys();
    Position* positionEntity = worldKeeperCl->getEntities()[enId]->getExtension<Position>("PositionExtension");

	{
		if(keysTrigger[GLFW_KEY_W] && !keysTrigger[GLFW_KEY_S]){
            if(positionEntity->getAccelerations().count("W") > 0){
                if(!positionEntity->getAccelerations()["W"]->getIsActive()){
                    positionEntity->getAccelerations()["W"]->setIsActive(true);
                    positionEntity->getAccelerations()["W"]->setStartTime(glfwGetTime());
                }
            }else{
                positionEntity->generateNewAcceleration(new Acceleration(glm::vec3{0.0, 0.1, 0.0}, glfwGetTime()), "W");
            }

		}else{
            if(positionEntity->getAccelerations().count("W") > 0){
                positionEntity->getAccelerations()["W"]->setIsActive(false);
            }
		}

		if(keysTrigger[GLFW_KEY_A] && !keysTrigger[GLFW_KEY_D]){
			if(positionEntity->getAccelerations().count("A") > 0){
                if(!positionEntity->getAccelerations()["A"]->getIsActive()){
                    positionEntity->getAccelerations()["A"]->setIsActive(true);
                    positionEntity->getAccelerations()["A"]->setStartTime(glfwGetTime());
                }
            }else{
                positionEntity->generateNewAcceleration(new Acceleration(glm::vec3{-0.1, 0.0, 0.0}, glfwGetTime()), "A");
            }

		}else{
            if(positionEntity->getAccelerations().count("A") > 0){
                positionEntity->getAccelerations()["A"]->setIsActive(false);
            }
		}

		if(keysTrigger[GLFW_KEY_S] && !keysTrigger[GLFW_KEY_W]){
			if(positionEntity->getAccelerations().count("S") > 0){
                if(!positionEntity->getAccelerations()["S"]->getIsActive()){
                    positionEntity->getAccelerations()["S"]->setIsActive(true);
                    positionEntity->getAccelerations()["S"]->setStartTime(glfwGetTime());
                }
            }else{
                positionEntity->generateNewAcceleration(new Acceleration(glm::vec3{0.0, -0.1, 0.0}, glfwGetTime()), "S");
            }

		}else{
            if(positionEntity->getAccelerations().count("S") > 0){
                positionEntity->getAccelerations()["S"]->setIsActive(false);
            }
		}
		
		if(keysTrigger[GLFW_KEY_D] && !keysTrigger[GLFW_KEY_A]){
			if(positionEntity->getAccelerations().count("D") > 0){
                if(!positionEntity->getAccelerations()["D"]->getIsActive()){
                    positionEntity->getAccelerations()["D"]->setIsActive(true);
                    positionEntity->getAccelerations()["D"]->setStartTime(glfwGetTime());
                }
            }else{
                positionEntity->generateNewAcceleration(new Acceleration(glm::vec3{0.1, 0.0, 0.0}, glfwGetTime()), "D");
            }

		}else{
            if(positionEntity->getAccelerations().count("D") > 0){
                positionEntity->getAccelerations()["D"]->setIsActive(false);
            }
		}
	}

	//std::cout << this->moveVector.x << std::endl;
	//std::cout << this->moveVector.y << std::endl;
}

glm::vec3 MoveMent::getVelocity(){
    return moveVector;
}

void MoveMent::setVelocity(glm::vec3 newVelocity){
    moveVector = newVelocity;
}
