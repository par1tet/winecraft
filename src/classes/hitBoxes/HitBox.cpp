#include <classes/hitBoxes/hitBox.hpp>
#include <glm/glm.hpp>
#include <vector>

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

std::vector<glm::vec3> HitBoxAABB::resolveCollision(const HitBox* otherHitBox){
    const HitBoxAABB* otherHitBoxAABB = dynamic_cast<const HitBoxAABB*>(otherHitBox);

    if(otherHitBoxAABB){
        return resolveCollision(otherHitBoxAABB);
    }

    return {glm::vec3{0.0f}};
}

std::vector<glm::vec3> HitBoxAABB::resolveCollision(const HitBoxAABB* otherHitBox){
    std::vector<glm::vec3> resolveVector;
    float percent = 0.5f; 

    glm::vec3 normal = glm::normalize(this->position - otherHitBox->position);

    float penetration = 1.0f;

    glm::vec3 correction = normal * penetration * percent;

    float mass1 = 1.0f;
    float mass2 = 1.0f;

    resolveVector.push_back(this->position + correction * (mass1 / (mass1 + mass2)));
    resolveVector.push_back(otherHitBox->position - correction * (mass2 / (mass1 + mass2)));

    return resolveVector;
}