#include <classes/extensions/object.hpp>
#include <classes/extensions/position.hpp>
#include <glm/glm.hpp>

glm::vec3 ObjectExtension::getAbsolutePosition(Entity* entity, int idObj){
    return (dynamic_cast<Position*>(entity->extensions["Position"])->position) + this->objects[idObj]->position;
}