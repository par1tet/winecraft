#include <classes/entities/entity.hpp>
#include "classes/hitBox/hitBox.hpp"
#include "classes/worldKeeper/worldKeeper.hpp"
#include<classes/extensions/collisionExtension/collisionExtension.hpp>
#include <iostream>
#include <string>
#include <vector>

CollisionExtension::CollisionExtension(std::vector<HitBox*> hitBoxes) : Extension() {
    this->hitBoxes = hitBoxes;
}

bool CollisionExtension::checkCollision(CollisionExtension* otherCollision){
    return false;
}

void CollisionExtension::gameFrame(WorldKeeper* worldKeeper, int enId){
    std::vector<Entity*> worldEntities = worldKeeper->getEntities();

    for(int i = 0;i != worldEntities.size();i++){
        if(i == enId) continue;

        CollisionExtension* otherCollisionExtension = worldEntities[i]->getExtension<CollisionExtension>("CollisionExtension");

        if(otherCollisionExtension){
            std::cout << this->checkCollision(otherCollisionExtension) << std::endl;
        }else{continue;}
    }
}

void CollisionExtension::gameInit(GLFWwindow* window){

}

std::string CollisionExtension::getExName(){return "CollisionExtension";}
