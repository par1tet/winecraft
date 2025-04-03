#include <classes/entities/entity.hpp>
#include "classes/hitBox/hitBox.hpp"
#include "classes/worldKeeper/worldKeeper.hpp"
#include<classes/extensions/collisionExtension/collisionExtension.hpp>
#include <glm/fwd.hpp>
#include <iostream>
#include <string>
#include <vector>

CollisionExtension::CollisionExtension(std::vector<HitBox*> hitBoxes) : Extension() {
    this->hitBoxes = hitBoxes;
}

bool CollisionExtension::checkCollision(CollisionExtension* otherCollision, Entity* thisEntity, Entity* secondEntity){
    for(int i = 0;i != this->getHitBoxes().size();i++){
        for(int j = 0;j != otherCollision->getHitBoxes().size();j++){
            bool resultCheckWith = this->getHitBoxes()[i]->collisionWith(otherCollision->getHitBoxes()[j], thisEntity, secondEntity);

            // std::cout << i << ":" << j << std::endl;
            if(resultCheckWith){
                return true;
            }
        }
    }
    return false;
}

void CollisionExtension::gameFrame(WorldKeeper* worldKeeper, int enId){
    std::vector<Entity*> worldEntities = worldKeeper->getEntities();
    std::cout << "huo: " << enId << std::endl;
    for(int i = 0;i != worldEntities.size();i++){
        if(i == enId) continue;

        CollisionExtension* otherCollisionExtension = worldEntities[i]->getExtension<CollisionExtension>("CollisionExtension");

        if(otherCollisionExtension){
            std::cout << "Check collision with: " << i << std::endl;

            bool resultCollision = this->checkCollision(otherCollisionExtension, worldEntities[enId], worldEntities[i]);

            std::cout << "resultCollision: " << resultCollision << std::endl;
        }else{continue;}
    }
}

void CollisionExtension::gameInit(GLFWwindow* window){

}

std::string CollisionExtension::getExName(){return "CollisionExtension";}

std::vector<HitBox*> CollisionExtension::getHitBoxes(){
    return hitBoxes;
}

glm::vec3 CollisionExtension::getAbsolutePosition(Entity* currentEntity, int hId){
    return this->getHitBoxes()[hId]->getAbsolutePositioin(currentEntity);
}
