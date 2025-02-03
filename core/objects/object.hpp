#include <glm/glm.hpp>
#include <string>

#ifndef object
#define object

class Object {
public:
  Object(glm::vec3 position, std::string texturePath) {
    this->position = position;
    this->texturePath = texturePath;
  }

  virtual void printPosition();

  glm::vec3 position;
  std::string texturePath;
};

// в конце заголовочного файла
#endif
