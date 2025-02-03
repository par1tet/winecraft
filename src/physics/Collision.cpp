#include "physics/collision.hpp"

bool Collision::checkCollision(const Collision *otherCollision) {
  for (int i = 0; i != this->hitBoxes.size(); ++i) {
    for (int j = 0; j != otherCollision->hitBoxes.size(); j++) {
      // std::cout << "endl" << std::endl;
      // std::cout << this->hitBoxes[i].position.x << std::endl;
      // std::cout <<
      // (this->hitBoxes[i]->checkCollision(otherCollision->hitBoxes[j])) <<
      // std::endl;

      if (this->hitBoxes[i]->checkCollision(otherCollision->hitBoxes[j])) {
        return true;
      }
    }
  }
  return false;
}
