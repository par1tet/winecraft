#include "objects/object.hpp"
#include <glm/glm.hpp>

class Cube : public Object {
public:
  Cube(glm::vec3 position, std::string texturePath, glm::vec3 size)
      : Object(position, texturePath) {
    this->size = size;
  }

  glm::vec3 position;
  std::string texturePath;
  glm::vec3 size;
};
