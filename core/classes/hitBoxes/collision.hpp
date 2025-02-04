#include<classes/hitBoxes/hitBox.hpp>
#include<vector>
#include<iostream>

#ifndef collisionclass
#define collisionclass

class Collision{
public:
    Collision(std::vector<HitBox*> hitBoxes){
        this->hitBoxes = hitBoxes;
    }

    bool checkCollision(const Collision *otherCollision);

    std::vector<HitBox*> hitBoxes;
};

#endif