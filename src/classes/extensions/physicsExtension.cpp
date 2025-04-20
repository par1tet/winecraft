#include "classes/extensions/positionExtension.hpp"
#include "classes/worldKeeper/worldKeeper.hpp"
#include<classes/extensions/physicsExtension.hpp>
#include <cstdlib>
#include <glm/ext/quaternion_geometric.hpp>
#include <glm/fwd.hpp>
#include <glm/geometric.hpp>
#include <iostream>
#include <ostream>

PhysicsExtension::PhysicsExtension(float mass, float elasticity, float friction){
    this->mass = mass;
    this->elasticity = elasticity;
    this->friction = friction;
}

void PhysicsExtension::gameFrame(float dTime, WorldKeeper* worldKeeperCl, int enId){
    Entity* thisEntity = worldKeeperCl->getEntities()[enId];

    Position* enPos = thisEntity->getExtension<Position>("PositionExtension");

    char a;
    //std::cin >> a;
    
    if(glm::length(enPos->getVelocity()) > 0.f){
        if(enPos->getAccelerations().count("PhysFriction") > 0){
            if(!enPos->getAccelerations()["PhysFriction"]->getIsActive()){
                enPos->getAccelerations()["PhysFriction"]->setIsActive(true);
            }

            enPos->getAccelerations()["PhysFriction"]->setAcceleration(-glm::normalize(enPos->getVelocity()) * (9.81f * friction));
        }else{
            enPos->generateNewAcceleration(new Acceleration(-glm::normalize(enPos->getVelocity()) * (9.81f * friction)), "PhysFriction");
        }
    }else{
        if(enPos->getAccelerations().count("PhysFriction") > 0){
            if(enPos->getAccelerations()["PhysFriction"]->getIsActive()){
                enPos->getAccelerations()["PhysFriction"]->setIsActive(false);
            }
        }
    }
    
    std::cout << glm::length(enPos->getVelocity()) << std::endl;

    // enPos->setVelocity(enPos->getVelocity() + (glm::normalize(glm::vec3(0.0f)) * (-9.81f * friction)));
}
