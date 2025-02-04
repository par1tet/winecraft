#include <classes/hitBoxes/collision.hpp>
#include <iostream>

bool Collision::checkCollision(const Collision *otherCollision){
    for(int i = 0;i != this->hitBoxes.size();++i){
        for(int j = 0;j != otherCollision->hitBoxes.size();j++){
            //std::cout << i << " : " << j << std::endl;

            
            if(this->hitBoxes[i]->checkCollision(otherCollision->hitBoxes[j])){

                return true;
            }
        }
    }

    return false;
}