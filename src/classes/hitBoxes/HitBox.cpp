#include <classes/hitBoxes/hitBox.hpp>
#include <glm/glm.hpp>

bool HitBoxAABB::checkCollision(const HitBox* otherHitBox){
    const HitBoxAABB* otherHitBoxAABB = dynamic_cast<const HitBoxAABB*>(otherHitBox);

    if(otherHitBoxAABB){
        return checkCollision(otherHitBoxAABB);
    }

    return HitBox::checkCollision(otherHitBox);
}

bool HitBoxAABB::checkCollision(const HitBoxAABB* otherHitBox){
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