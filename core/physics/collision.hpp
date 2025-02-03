#include <physics/HitBox.hpp>
#include <vector>

#ifndef collision
#define collision
class Collision {
public:
  Collision(std::vector<HitBox *> hitBoxes) { this->hitBoxes = hitBoxes; }

  bool checkCollision(const Collision *otherCollision);

  std::vector<HitBox *> hitBoxes;
};

#endif // !Collision
