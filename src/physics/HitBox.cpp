// #include "physics/HitBox.hpp"
// #include <iostream>
// #include <string>
// #include <vector>

// bool HitBox::checkCollision(const HitBox *OtherHitBox) { return false; }

// bool HitBoxAABB::checkCollisionAABB(const HitBoxAABB *OtherHitBox) {
//   std::vector<glm::vec3> diaFirst = {
//       this->position - (this->size / 2.0f),
//       this->position + (this->size / 2.0f),
//   };

//   std::vector<glm::vec3> diaSecond = {
//       OtherHitBox->position - (OtherHitBox->size / 2.0f),
//       OtherHitBox->position + (OtherHitBox->size / 2.0f),
//   };

//   if ((diaFirst[1][0] >= diaSecond[0][0] &&
//        diaSecond[1][0] >= diaFirst[0][0]) &&
//       (diaFirst[1][1] >= diaSecond[0][1] &&
//        diaSecond[1][1] >= diaFirst[0][1]) &&
//       (diaFirst[1][2] >= diaSecond[0][2] &&
//        diaSecond[1][2] >= diaFirst[0][2])) {
//     return true;
//   }

//   return false;
// }

// bool HitBoxAABB::checkCollision(const HitBox *OtherHitBox) {
//   const HitBoxAABB *OtherHitBoxAABB =
//       dynamic_cast<const HitBoxAABB *>(OtherHitBox);

//   if (OtherHitBoxAABB) {
//     return checkCollision(OtherHitBoxAABB);
//   }

//   return HitBox::checkCollision(OtherHitBox);
// }
