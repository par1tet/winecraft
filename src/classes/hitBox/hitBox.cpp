#include "classes/extensions/positionExtension.hpp"
#include<classes/hitBox/hitBox.hpp>
#include <glm/fwd.hpp>
#include <classes/entities/entity.hpp>

bool HitBox::collisionWith(HitBox* o, Entity*, Entity*){return false;}
bool HitBox::collisionWithRect(HitBoxRect* o, Entity*, Entity*){return false;}

HitBox::HitBox(glm::vec3 position){
    this->position = position;
}

glm::vec3 HitBox::getPosition(){
    return position;
}

glm::vec3 HitBox::getAbsolutePositioin(Entity* thisEntity){
    return this->getPosition() + thisEntity->getExtension<Position>("PositionExtension")->getPosition();
}
