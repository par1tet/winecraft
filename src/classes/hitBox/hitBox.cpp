#include "classes/extensions/positionExtension.hpp"
#include<classes/hitBox/hitBox.hpp>
#include <glm/fwd.hpp>
#include <classes/entities/entity.hpp>

glm::vec3 HitBox::collisionWith(HitBox* o, Entity*, Entity*) const 
{return glm::vec3{0.f};}
glm::vec3 HitBox::collisionWithRect(const HitBoxRect* o, Entity*, Entity*) const {return glm::vec3{0.f};}

HitBox::HitBox(glm::vec3 position){
    this->position = position;
}

glm::vec3 HitBox::getPosition() const{
    return position;
}

glm::vec3 HitBox::getAbsolutePositioin(Entity* thisEntity) const {
    return this->getPosition() + thisEntity->getExtension<Position>("PositionExtension")->getPosition();
}
