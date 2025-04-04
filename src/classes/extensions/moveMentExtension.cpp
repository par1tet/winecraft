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

MoveMent::MoveMent(double maxSpeed, double runUpTime) : Extension(){
	this->maxSpeed = maxSpeed;
	this->runUpTime = runUpTime;
}

void MoveMent::gameInit(GLFWwindow* window){}
std::string MoveMent::getExName(){return "MoveMentExtension";}

void MoveMent::gameFrame(WorldKeeper* worldKeeperCl, int enId){
    Entity* thisEntity = worldKeeperCl->getEntities()[enId];
    std::cout << "conchil" << std::endl;

	bool* keysTrigger = worldKeeperCl->getKeyTrigger()->getKeys();
    Position* positionEntity = worldKeeperCl->getEntities()[enId]->getExtension<Position>("PositionExtension");

	{
		if(keysTrigger[GLFW_KEY_W] && !keysTrigger[GLFW_KEY_S]){
			if(positionEntity->getVelocity().y < this->maxSpeed){
				if(positionEntity->getVelocity().y + this->runUpTime > this->maxSpeed){
					positionEntity->setVelocityY(this->maxSpeed);
				}else{
                    positionEntity->setVelocityY(positionEntity->getVelocity().y + this->runUpTime);
				}
			}
		}else{
			if(positionEntity->getVelocity().y > 0.0f){
				if(positionEntity->getVelocity().y - this->runUpTime < 0){
					positionEntity->setVelocityY(0);
				}else{
                    positionEntity->setVelocityY(positionEntity->getVelocity().y - this->runUpTime);
				}
			}
		}

		if(keysTrigger[GLFW_KEY_A] && !keysTrigger[GLFW_KEY_D]){
			if(positionEntity->getVelocity().x > -this->maxSpeed){
				if(positionEntity->getVelocity().x - this->runUpTime < -this->maxSpeed){
					positionEntity->setVelocityX(-this->maxSpeed);
				}else{
                    positionEntity->setVelocityX(positionEntity->getVelocity().x - this->runUpTime);
				}
			}

		}else{
			if(positionEntity->getVelocity().x < 0.0f){
				if(positionEntity->getVelocity().x + this->runUpTime > 0){
					positionEntity->setVelocityX(0);
				}else{
                    positionEntity->setVelocityX(positionEntity->getVelocity().x + this->runUpTime);
				}
			}
		}

		if(keysTrigger[GLFW_KEY_S] && !keysTrigger[GLFW_KEY_W]){
			if(positionEntity->getVelocity().y > -this->maxSpeed){
				if(positionEntity->getVelocity().y - this->runUpTime < -this->maxSpeed){
					positionEntity->setVelocityY(-this->maxSpeed);
				}else{
                    positionEntity->setVelocityY(positionEntity->getVelocity().y - this->runUpTime);
				}
			}

		}else{
			if(positionEntity->getVelocity().y < 0.0f){
				if(positionEntity->getVelocity().y + this->runUpTime > 0){
					positionEntity->setVelocityY(0);
				}else{
                    positionEntity->setVelocityY(positionEntity->getVelocity().y + this->runUpTime);
				}
			}
		}  
		
		if(keysTrigger[GLFW_KEY_D] && !keysTrigger[GLFW_KEY_A]){
			if(positionEntity->getVelocity().x < this->maxSpeed){
				if(positionEntity->getVelocity().x + this->runUpTime > this->maxSpeed){
					positionEntity->setVelocityX(this->maxSpeed);
				}else{
                    positionEntity->setVelocityX(positionEntity->getVelocity().x + this->runUpTime);
				}
			}
		}else{
			if(positionEntity->getVelocity().x > 0.0f){
				if(positionEntity->getVelocity().x - this->runUpTime < 0){
					positionEntity->setVelocityX(0);
				}else{
                    positionEntity->setVelocityX(positionEntity->getVelocity().x - this->runUpTime);
				}
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
