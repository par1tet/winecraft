#include <classes/entities/entity.hpp>
#include "classes/hitBox/hitBox.hpp"
#include "classes/worldKeeper/worldKeeper.hpp"
#include<classes/extensions/collisionExtension/collisionExtension.hpp>
#include <glm/fwd.hpp>
#include <iostream>
#include <string>
#include <vector>

CollisionExtension::CollisionExtension(std::vector<HitBox*> hitBoxes, float mass, float elasticity) : Extension() {
    this->hitBoxes = hitBoxes;
    this->mass = mass;
    this->elasticity = elasticity;
}

CollisionExtension::CollisionExtension(std::vector<HitBox*> hitBoxes) : Extension() {
    this->hitBoxes = hitBoxes;
    this->mass = 0.0;
    this->elasticity = 0;
}

void CollisionExtension::checkCollision(CollisionExtension* otherCollision, Entity* thisEntity, Entity* secondEntity){
    for(int i = 0;i != this->getHitBoxes().size();i++){
        for(int j = 0;j != otherCollision->getHitBoxes().size();j++){
            this->getHitBoxes()[i]->collisionWith(otherCollision->getHitBoxes()[j], thisEntity, secondEntity);
        }
    }
}

void CollisionExtension::gameFrame(WorldKeeper* worldKeeper, int enId){
    std::vector<Entity*> worldEntities = worldKeeper->getEntities();
    std::cout << "huo: " << enId << std::endl;
    for(int i = 0;i != worldEntities.size();i++){
        if(i >= enId) continue;

        CollisionExtension* otherCollisionExtension = worldEntities[i]->getExtension<CollisionExtension>("CollisionExtension");
        std::cout << "collisionWith: " << i << std::endl;

        if(otherCollisionExtension){
            this->checkCollision(otherCollisionExtension, worldEntities[enId], worldEntities[i]);
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

float CollisionExtension::getElasticity(){
    return elasticity;
}

float CollisionExtension::getMass(){
    return mass;
}
