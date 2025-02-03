#include <glm/glm.hpp>
#ifndef hitBox
#define hitBox
class HitBox {
public:
  HitBox(glm::vec3 position) { this->position = position; }

  virtual bool checkCollision(const HitBox *OtherHitBox);

  glm::vec3 position;
};

class HitBoxAABB : public HitBox {
public:
  HitBoxAABB(glm::vec3 position, glm::vec3 size) : HitBox(position) {
    this->size = size;
  }

  bool checkCollision(const HitBox *OtherHitBox);

  bool checkCollisionAABB(const HitBoxAABB *OtherHitBox);

  glm::vec3 size;
};

#endif // !HitBoxes
