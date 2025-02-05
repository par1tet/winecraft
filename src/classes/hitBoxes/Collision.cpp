#include <classes/hitBoxes/collision.hpp>
#include <iostream>
#include <glm/glm.hpp>

bool Collision::checkCollision(const Collision *otherCollision){
    for(int i = 0;i != this->hitBoxes.size();++i){
        for(int j = 0;j != otherCollision->hitBoxes.size();j++){
            if(this->hitBoxes[i]->checkCollision(otherCollision->hitBoxes[j])){
                return true;
            }
        }
    }
    return false;
}

glm::vec3 Collision::resolveCollision(int demension, const Collision* otherCollision){
    glm::vec3 resolveVector{0.0f};

    return resolveVector;
}