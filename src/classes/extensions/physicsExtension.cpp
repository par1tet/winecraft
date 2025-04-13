#include "classes/extensions/positionExtension.hpp"
#include "classes/worldKeeper/worldKeeper.hpp"
#include<classes/extensions/physicsExtension.hpp>
#include <cstdlib>
#include <glm/ext/quaternion_geometric.hpp>
#include <glm/fwd.hpp>
#include <glm/geometric.hpp>
#include <iostream>
#include <ostream>

PhysicsExtension::PhysicsExtension(float mass, float maxSpeed, float elasticity, float friction){
    this->mass = mass;
    this->maxSpeed = maxSpeed;
    this->elasticity = elasticity;
    this->friction = friction;
}

void PhysicsExtension::gameFrame(WorldKeeper* worldKeeperCl, int enId){
    Entity* thisEntity = worldKeeperCl->getEntities()[enId];

    Position* enPos = thisEntity->getExtension<Position>("PositionExtension");

    char a;
    //std::cin >> a;
    
    if(glm::length(enPos->getVelocity()) >= 0.001f){
        if(enPos->getAccelerations().count("PhysFriction") > 0){
            if(!enPos->getAccelerations()["PhysFriction"]->getIsActive()){
                enPos->getAccelerations()["PhysFriction"]->setIsActive(true);
                enPos->getAccelerations()["PhysFriction"]->setStartTime(glfwGetTime());
            }
            if(glm::length(-glm::normalize(enPos->getVelocity()) * (9.81f * friction)) >= glm::length(enPos->getVelocity())){
                enPos->setVelocity(glm::vec3(0.0f));
                enPos->getAccelerations()["PhysFriction"]->setAcceleration(glm::vec3{0.0f});
                enPos->getAccelerations()["PhysFriction"]->setIsActive(false);
            }else{
                enPos->getAccelerations()["PhysFriction"]->setAcceleration(-glm::normalize(enPos->getVelocity()) * (9.81f * friction));
            }
        }else{
            enPos->generateNewAcceleration(new Acceleration(-glm::normalize(enPos->getVelocity()) * (9.81f * friction), glfwGetTime()), "PhysFriction");
        }
    }else{
        if(enPos->getAccelerations().count("PhysFriction") > 0){
            if(enPos->getAccelerations()["PhysFriction"]->getIsActive()){
                enPos->getAccelerations()["PhysFriction"]->setIsActive(false);
            }
        }

        enPos->setVelocity(glm::vec3(0.0f));
    }

    std::cout << glm::length(glm::normalize(enPos->getVelocity()) * (9.81f * friction)) << std::endl;
    std::cout << glm::length(enPos->getVelocity()) << std::endl;

    // enPos->setVelocity(enPos->getVelocity() + (glm::normalize(glm::vec3(0.0f)) * (-9.81f * friction)));
}
