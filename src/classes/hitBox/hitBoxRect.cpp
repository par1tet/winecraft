#include "classes/entities/entity.hpp"
#include "classes/extensions/collisionExtension/collisionExtension.hpp"
#include "classes/extensions/moveMentExtension.hpp"
#include "classes/extensions/positionExtension.hpp"
#include <algorithm>
#include <classes/hitBox/hitBoxRect.hpp>
#include <cmath>
#include <cstdlib>
#include <glm/common.hpp>
#include <glm/fwd.hpp>
#include <glm/geometric.hpp>
#include <iostream>
#include <ostream>
#include <vector>

HitBoxRect::HitBoxRect(glm::vec3 position, glm::vec3 size) : HitBox(position) {
    this->size = size;
}

void HitBoxRect::collisionWith(HitBox* otherClass, Entity* en, Entity* sEn){
    otherClass->collisionWithRect(this, sEn, en);
}

void HitBoxRect::collisionWithRect(HitBoxRect* otherHitBox, Entity* en, Entity* sEn){
    Position* position1 = en->getExtension<Position>("PositionExtension");
    Position* position2 = sEn->getExtension<Position>("PositionExtension");
    CollisionExtension* collision1 = en->getExtension<CollisionExtension>("CollisionExtension");
    CollisionExtension* collision2 = sEn->getExtension<CollisionExtension>("CollisionExtension");

    std::vector<glm::vec3> diaFirst = {
         this->getAbsolutePositioin(en) + position1->getVelocity() - (this->getSize() / 2.0f),
         this->getAbsolutePositioin(en) + position1->getVelocity() + (this->getSize() / 2.0f),
    };

    // std::cout << "xOur: " << otherHitBox->getAbsolutePositioin(sEn).x << std::endl;
    // std::cout << "yOur: " << otherHitBox->getAbsolutePositioin(sEn).y << std::endl;

    // std::cout << "xSec: " << this->getAbsolutePositioin(en).x << std::endl;
    // std::cout << "ySec: " << this->getAbsolutePositioin(en).y << std::endl;

    std::vector<glm::vec3> diaSecond = {
        otherHitBox->getAbsolutePositioin(sEn) + position2->getVelocity() - (otherHitBox->getSize() / 2.0f),
        otherHitBox->getAbsolutePositioin(sEn) + position2->getVelocity() + (otherHitBox->getSize() / 2.0f),
    };
    if ((diaFirst[1][0] >= diaSecond[0][0] && diaSecond[1][0] >= diaFirst[0][0]) &&
        (diaFirst[1][1] >= diaSecond[0][1] && diaSecond[1][1] >= diaFirst[0][1]) &&
        (diaFirst[1][2] >= diaSecond[0][2] && diaSecond[1][2] >= diaFirst[0][2])){

        glm::vec3 overlaps = (this->getAbsolutePositioin(en) + this->getSize() / 2.0f) - (otherHitBox->getAbsolutePositioin(sEn) + otherHitBox->getSize() / 2.0f);

        glm::vec3 normal(0.0f);
        float minOverlap = std::min({ overlaps.x, overlaps.y, overlaps.z });

        if (minOverlap == overlaps.x) {
            normal.x = (diaFirst[1].x > diaSecond[1].x) ? 1 : -1;
        } else if (minOverlap == overlaps.y) {
            normal.y = (diaFirst[1].y > diaSecond[1].y) ? 1 : -1;
        } else {
            normal.z = (diaFirst[1].z > diaSecond[1].z) ? 1 : -1;
        }        

        float fullElasticity = (collision1->getElasticity() + collision2->getElasticity()) / 2.0f;
        float fullMass = collision1->getMass() + collision2->getMass();

        glm::vec3 rVelocity = position1->getVelocity() - position2->getVelocity();

        float velAlongNormal = glm::dot(rVelocity, normal);
        
        if (velAlongNormal > 0) return;

        float impulseCoefficient = (-(1 + fullElasticity) * velAlongNormal);

        if(fullMass != 0)
            impulseCoefficient /= fullMass;

        glm::vec3 fullImpulse = impulseCoefficient * normal;

        //position1->setVelocity(position1->getVelocity() + (fullImpulse / collision1->getMass()));
        //position2->setVelocity(position2->getVelocity() + (fullImpulse / collision2->getMass()));

        glm::vec3 correction = normal * minOverlap;

        if(fullMass != 0){
            correction /= fullMass;
        }

        //position1->setPosition(position1->getPosition() + correction * collision1->getMass());        
        //position2->setPosition(position2->getPosition() - correction * collision2->getMass());        
    }
    // position1->setPosition(position1->getPosition() + position1->getVelocity());
    // position2->setPosition(position2->getPosition() + position2->getVelocity());
}

glm::vec3 HitBoxRect::getSize(){
    return size;
}
