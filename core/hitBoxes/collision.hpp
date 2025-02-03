#include<hitBoxes/hitBox.hpp>
#include<vector>

class Collision{
public:
    Collision(std::vector<HitBox> hitBoxes){
        this->hitBoxes = hitBoxes;
    }

    bool checkCollision(const Collision &otherCollision){
        for(int i = 0;i != hitBoxes.size();i++){
            for(int j = 0;j != otherCollision.hitBoxes.size();j++){
                if(hitBoxes[i].checkCollision(otherCollision.hitBoxes[j])){
                    return true;
                }
            }
        }

        return false;
    }

    std::vector<HitBox> hitBoxes;
};