#include<classes/extensions/moveMent.hpp>
#include<classes/entities/entity.hpp>
#include<classes/extensions/position.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<classes/worldKeeper/keyTrigger.hpp>
#include<stdio.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>

void MoveMent::gameInit(GLFWwindow* window){
}

void MoveMent::gameFrame(WorldKeeper* worldKeeperCl, int enId){
    Entity* thisEntity = worldKeeperCl->entities[enId];

	bool* keysTrigger = worldKeeperCl->keyTrigger->keys;

	{
		if(keysTrigger[GLFW_KEY_W] && !keysTrigger[GLFW_KEY_S]){
			if(this->moveVector.y < this->maxSpeed){
				if(this->moveVector.y + this->runUpTime > this->maxSpeed){
					this->moveVector.y = this->maxSpeed;
				}else{
					this->moveVector.y += this->runUpTime;
				}
			}
		}else{
			if(this->moveVector.y > 0.0f){
				if(this->moveVector.y - this->runUpTime < 0){
					this->moveVector.y = 0;
				}else{
					this->moveVector.y -= this->runUpTime;
				}
			}
		}

		if(keysTrigger[GLFW_KEY_A] && !keysTrigger[GLFW_KEY_D]){
			if(this->moveVector.x > -this->maxSpeed){
				if(this->moveVector.x - this->runUpTime < -this->maxSpeed){
					this->moveVector.x = -this->maxSpeed;
				}else{
					this->moveVector.x -= this->runUpTime;
				}
			}

		}else{
			if(this->moveVector.x < 0.0f){
				if(this->moveVector.x + this->runUpTime > 0){
					this->moveVector.x = 0;
				}else{
					this->moveVector.x += this->runUpTime;
				}
			}
		}

		if(keysTrigger[GLFW_KEY_S] && !keysTrigger[GLFW_KEY_W]){
			if(this->moveVector.y > -this->maxSpeed){
				if(this->moveVector.y - this->runUpTime < -this->maxSpeed){
					this->moveVector.y = -this->maxSpeed;
				}else{
					this->moveVector.y -= this->runUpTime;
				}
			}

		}else{
			if(this->moveVector.y < 0.0f){
				if(this->moveVector.y + this->runUpTime > 0){
					this->moveVector.y = 0;
				}else{
					this->moveVector.y += this->runUpTime;
				}
			}
		}  
		
		if(keysTrigger[GLFW_KEY_D] && !keysTrigger[GLFW_KEY_A]){
			if(this->moveVector.x < this->maxSpeed){
				if(this->moveVector.x + this->runUpTime > this->maxSpeed){
					this->moveVector.x = this->maxSpeed;
				}else{
					this->moveVector.x += this->runUpTime;
				}
			}
		}else{
			if(this->moveVector.x > 0.0f){
				if(this->moveVector.x - this->runUpTime < 0){
					this->moveVector.x = 0;
				}else{
					this->moveVector.x -= this->runUpTime;
				}
			}
		}
	}

	std::cout << this->moveVector.x << std::endl;
	std::cout << this->moveVector.y << std::endl;
	
	thisEntity->getExtension<Position>("Position")->position += this->moveVector;
}