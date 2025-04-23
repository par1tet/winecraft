#include <classes/entities/entity.hpp>
#include "classes/extensions/positionExtension.hpp"
#include "classes/hitBox/hitBox.hpp"
#include "classes/worldKeeper/worldKeeper.hpp"
#include<classes/extensions/collisionExtension/collisionExtension.hpp>
#include <glm/ext/quaternion_geometric.hpp>
#include <glm/fwd.hpp>
#include <glm/geometric.hpp>
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

bool isPositiveVector(glm::vec3 vector){
    for(int j = 0;j != 3;j++){
        if(vector[j] < 0) return false;
    }
    return true;
}

void CollisionExtension::checkCollision(CollisionExtension* otherCollision, Entity* thisEntity, Entity* secondEntity){
    std::vector<glm::vec3> distances;
    Position* pos = thisEntity->getExtension<Position>("PositionExtension");
    Position* otherPos = secondEntity->getExtension<Position>("PositionExtension");
    
    for(int i = 0;i != this->getHitBoxes().size();i++){
        for(int j = 0;j != otherCollision->getHitBoxes().size();j++){
            distances.push_back(this->getHitBoxes()[i]->collisionWith(otherCollision->getHitBoxes()[j], thisEntity, secondEntity));
        }
    }

    for(int i = 0;i != distances.size();i++){
        std::cout << "x " << distances[i].x << " y " << distances[i].y << " z " << distances[i].z << std::endl;

        if(!isPositiveVector(distances[i])) continue;

        otherPos->setVelocity(glm::vec3(0.0f));
        otherPos->changePosition(-otherPos->getVelocity() * 1.f/60.f);
        otherPos->setAccelerations({}, {});

        pos->setVelocity(glm::vec3(0.0f));
        pos->changePosition(-pos->getVelocity() * 1.f/60.f);
        pos->setAccelerations({}, {});
    }
}

void CollisionExtension::gameFrame(float dTime, WorldKeeper* worldKeeper, int enId){
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
