#include <classes/extensions/object.hpp>
#include <classes/extensions/position.hpp>
#include <glm/glm.hpp>
#include <string>
#include <vector>

ObjectExtension::ObjectExtension(std::vector<Object*> objects) : Extension(){
    this->objects = objects;
} 

glm::vec3 ObjectExtension::getAbsolutePosition(Entity* entity, int idObj){
    return (dynamic_cast<Position*>(entity->getExtensions()["Position"])->getPosition()) + this->objects[idObj]->getPosition();
}

std::vector<Object*> ObjectExtension::getObjects(){return objects;}

std::string ObjectExtension::getExName(){return "ObjectExtension";}