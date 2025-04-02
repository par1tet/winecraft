#include "classes/hitBox/hitBoxRect.hpp"
#include <glm/fwd.hpp>
#include <vector>

HitBoxRect::HitBoxRect(glm::vec3 position, glm::vec3 size) : HitBox(){
    this->position = position;
    this->size = size;
}

bool HitBoxRect::collisionWith(HitBox* otherClass){
    return otherClass->collisionWithRect(this);
}

bool HitBoxRect::collisionWithRect(HitBoxRect* otherHitBox){
    std::vector<glm::vec3> diaFirst = {
         this->position - (this->size / 2.0f),
         this->position + (this->size / 2.0f),
     };

     std::vector<glm::vec3> diaSecond = {
         otherHitBox->position - (otherHitBox->size / 2.0f),
         otherHitBox->position + (otherHitBox->size / 2.0f),
     };

     if((diaFirst[1][0] >= diaSecond[0][0] && diaSecond[1][0] >= diaFirst[0][0]) &&
         (diaFirst[1][1] >= diaSecond[0][1] && diaSecond[1][1] >= diaFirst[0][1]) &&
         (diaFirst[1][2] >= diaSecond[0][2] && diaSecond[1][2] >= diaFirst[0][2])){
         return true;
     }

     return false;
}
