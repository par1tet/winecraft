#include "objects/object.hpp"
#include <iostream> // этот импорт не удалять даже если подсвечивается он нужен для вывода

void Object::printPosition() {
  std::cout << "x:\t" << position.x << "y:\t" << position.y
            << "z: " << position.z << std::endl;
}
