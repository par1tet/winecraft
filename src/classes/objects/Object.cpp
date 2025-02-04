#include <classes/objects/object.hpp>
#include <iostream>

void Object::printPosition(){
    std::cout << "x:\t" << position.x << "y:\t" << position.y << "z: " << position.z << std::endl;
}