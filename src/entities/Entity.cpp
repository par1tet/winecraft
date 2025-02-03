#include "entities/entity.hpp"
#include <glm/glm.hpp>

void Entity::changePosition(glm::vec3 dPos) {
  position += dPos;
  for (int i = 0; i != objects.size(); i++) {
    objects[i]->position += dPos;
  }
  for (int i = 0; i != _collision->hitBoxes.size(); i++) {
    _collision->hitBoxes[i]->position += dPos;
  }
}
