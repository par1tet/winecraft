#include "classes/entities/entity.hpp"
#include "classes/extensions/collisionExtension/collisionExtension.hpp"
#include "classes/extensions/moveMentExtension.hpp"
#include "classes/extensions/positionExtension.hpp"
#include <algorithm>
#include <classes/hitBox/hitBoxRect.hpp>
#include <cmath>
#include <cstdlib>
#include <glm/common.hpp>
#include <glm/ext/quaternion_geometric.hpp>
#include <glm/fwd.hpp>
#include <glm/geometric.hpp>
#include <iostream>
#include <ostream>
#include <vector>
#include <assert.h>

HitBoxRect::HitBoxRect(glm::vec3 position, glm::vec3 size) : HitBox(position) {
    this->size = size;
}

glm::vec3 HitBoxRect::collisionWith(HitBox* otherClass, Entity* en, Entity* sEn) const {
    return otherClass->collisionWithRect(this, sEn, en);
}

int invertZeroToOne(int n){
    if(n == 1) return 0;
    return 1;
}

glm::vec3 HitBoxRect::collisionWithRect(const HitBoxRect* otherHitBox, Entity* en, Entity* sEn) const {
    Position* position1 = en->getExtension<Position>("PositionExtension");
    Position* position2 = sEn->getExtension<Position>("PositionExtension");
    CollisionExtension* collision1 = en->getExtension<CollisionExtension>("CollisionExtension");
    CollisionExtension* collision2 = sEn->getExtension<CollisionExtension>("CollisionExtension");

    float dTime = 1.f/60.f;

    glm::vec3 updatePositionVector1 = (position1->getVelocity() + position1->getFullAcceleration(dTime) * dTime) * dTime;
    glm::vec3 updatePositionVector2  = (position2->getVelocity() + position2->getFullAcceleration(dTime) * dTime) * dTime;

    std::vector<glm::vec3> diaFirst = {
         (this->getAbsolutePositioin(en) - (this->getSize() / 2.0f)) + updatePositionVector1,
         (this->getAbsolutePositioin(en) + (this->getSize() / 2.0f)) + updatePositionVector1,
    };

    // std::cout << "xOur: " << otherHitBox->getAbsolutePositioin(sEn).x << std::endl;
    // std::cout << "yOur: " << otherHitBox->getAbsolutePositioin(sEn).y << std::endl;

    // std::cout << "xSec: " << this->getAbsolutePositioin(en).x << std::endl;
    // std::cout << "ySec: " << this->getAbsolutePositioin(en).y << std::endl;

    std::vector<glm::vec3> diaSecond = {
        (otherHitBox->getAbsolutePositioin(sEn) - (otherHitBox->getSize() / 2.0f)) + updatePositionVector2,
        (otherHitBox->getAbsolutePositioin(sEn) + (otherHitBox->getSize() / 2.0f)) + updatePositionVector2,
    };

    glm::vec3 overlap = glm::min(diaFirst[1], diaSecond[1]) - glm::max(diaFirst[0], diaSecond[0]); ;

    if ((diaFirst[1][0] >= diaSecond[0][0] && diaSecond[1][0] >= diaFirst[0][0]) &&
        (diaFirst[1][1] >= diaSecond[0][1] && diaSecond[1][1] >= diaFirst[0][1]) &&
        (diaFirst[1][2] >= diaSecond[0][2] && diaSecond[1][2] >= diaFirst[0][2])){
        std::cout << "penesito" << std::endl;



        glm::vec3 firstPersonPrecent = (position1->getVelocity() + position2->getVelocity()) / (position1->getVelocity());

        for(int i = 0;i != 3;i++){
            std::cout << firstPersonPrecent[i] << std::endl;

            if(position1->getVelocity()[i] == 0) firstPersonPrecent[i] = 0;

            std::cout << firstPersonPrecent[i] << std::endl;
        }

        glm::vec3 vec = glm::normalize(position1->getFullVelocity(dTime));
        //vec /= glm::abs(vec);

        for(int i = 0;i != 3;i++){if(position1->getFullVelocity(dTime)[i] == 0){vec[i] = 0;}}

        std::cout << "x: " << vec.x << " y: " << vec.y << " z: " << vec.z << std::endl;

        glm::vec3 correction1 = glm::vec3{0.f};
        glm::vec3 correction2 = (1.f - firstPersonPrecent) * overlap;

        int smallest = 0;

        for(int i = 0;i != 3;i++){
            if(overlap[i] < overlap[smallest]){
                smallest = i;
            }
        }

        correction1[smallest] = -(position1->getFullVelocity(dTime) * dTime)[smallest];

        std::cout << "x: " << correction1.x << " y: " << correction1.y << " z: " << correction1.z << std::endl;
        std::cout << "x: " << overlap.x << " y: " << overlap.y << " z: " << overlap.z << std::endl;

        std::string a;
        //std::cin >> a;

        position1->setPosition(position1->getPosition() + correction1);
        //position2->setPosition(position2->getPosition() + correction2);        
    }
    // position1->setPosition(position1->getPosition() + position1->getVelocity());
    // position2->setPosition(position2->getPosition() + position2->getVelocity());

    return overlap;
}

glm::vec3 HitBoxRect::getSize() const {
    return size;
}
