#include "classes/entities/entity.hpp"
#include <classes/hitBox/hitBoxRect.hpp>
#include <glm/fwd.hpp>
#include <iostream>
#include <vector>

HitBoxRect::HitBoxRect(glm::vec3 position, glm::vec3 size) : HitBox(position) {
    this->size = size;
}

bool HitBoxRect::collisionWith(HitBox* otherClass, Entity* en, Entity* sEn){
    return otherClass->collisionWithRect(this, sEn, en);
}

bool HitBoxRect::collisionWithRect(HitBoxRect* otherHitBox, Entity* en, Entity* sEn){
    std::vector<glm::vec3> diaFirst = {
         this->getAbsolutePositioin(en) - (this->getSize() / 2.0f),
         this->getAbsolutePositioin(en) + (this->getSize() / 2.0f),
    };

    // std::cout << "xOur: " << otherHitBox->getAbsolutePositioin(sEn).x << std::endl;
    // std::cout << "yOur: " << otherHitBox->getAbsolutePositioin(sEn).y << std::endl;

    // std::cout << "xSec: " << this->getAbsolutePositioin(en).x << std::endl;
    // std::cout << "ySec: " << this->getAbsolutePositioin(en).y << std::endl;

    std::vector<glm::vec3> diaSecond = {
        otherHitBox->getAbsolutePositioin(sEn) - (otherHitBox->getSize() / 2.0f),
        otherHitBox->getAbsolutePositioin(sEn) + (otherHitBox->getSize() / 2.0f),
    };

    return ((diaFirst[1][0] >= diaSecond[0][0] && diaSecond[1][0] >= diaFirst[0][0]) &&
        (diaFirst[1][1] >= diaSecond[0][1] && diaSecond[1][1] >= diaFirst[0][1]) &&
        (diaFirst[1][2] >= diaSecond[0][2] && diaSecond[1][2] >= diaFirst[0][2]));
}

glm::vec3 HitBoxRect::getSize(){
    return size;
}
