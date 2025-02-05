#include<classes/hitBoxes/hitBox.hpp>
#include<vector>
#include<iostream>
#include<glm/glm.hpp>

#ifndef collisionclass
#define collisionclass

class Collision{
public:
    Collision(std::vector<HitBox*> hitBoxes){
        this->hitBoxes = hitBoxes;
    }

    bool checkCollision(const Collision *otherCollision);
    glm::vec3 resolveCollision(int demension, const Collision *otherCollision);

    std::vector<HitBox*> hitBoxes;
};

#endif