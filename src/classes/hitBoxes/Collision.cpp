// #include <classes/hitBoxes/collision.hpp>
// #include <iostream>
// #include <glm/glm.hpp>
// #include <vector>

// using namespace std;

// void Collision::checkCollision(const Collision* otherCollision){
//     // cout << "dont collision" << endl;
//     for(int i = 0;i != this->hitBoxes.size();++i){
//         for(int j = 0;j != otherCollision->hitBoxes.size();j++){
//             if(this->hitBoxes[i]->checkCollision(otherCollision->hitBoxes[j])){
//                 return;
//             }
//         }
//     }

//     //cout << "OtherCollision" << endl;

//     for(int i = 0;i != otherCollision->hitBoxes.size();i++){
//         for(int j = 0;j != 3;j++){
//             //cout << otherCollision->hitBoxes.at(i)->position[j];
//             //if(j != 2) cout << ",";
//         }
//         //cout << endl;
//     }

//     //cout << endl;

//     //cout << "This" << endl;

//     for(int i = 0;i != otherCollision->hitBoxes.size();i++){
//         // if(i != 1)continue;
//         glm::vec3 defPosition =
//             this->hitBoxes.at(i)->position - otherCollision->hitBoxes.at(i)->position;


//         for(int j = 0;j != 3;j++){
//             //cout << this->hitBoxes.at(i)->position[j];


//             //if(j == 1)cout << ",";
//         }

//         //cout << endl << "DefPosition: " << i << endl;

//         for(int j = 0;j != 3;j++){
//             //cout << j << ": " << defPosition[j] << endl;
//         }

//         float xBorderDiff = defPosition[0] - dynamic_cast<HitBoxAABB*>(this->hitBoxes.at(i))->size[0] + 
//         dynamic_cast<HitBoxAABB*>(otherCollision->hitBoxes.at(i))->size[0];

//         //cout << 0 << ": " << xBorderDiff << endl;

//         if(xBorderDiff < 0 && xBorderDiff < (
//             dynamic_cast<HitBoxAABB*>(otherCollision->hitBoxes.at(i))->size[0]) + dynamic_cast<HitBoxAABB*>(this->hitBoxes.at(i))->size[0]){
//             //cout << "collision" << endl;
//         }
//     }

//     cout << endl;
// }

// void Collision::resolveCollision(const Collision* otherCollision){
//     //cout << "dont collision" << endl;
//     for(int i = 0;i != this->hitBoxes.size();++i){
//         for(int j = 0;j != otherCollision->hitBoxes.size();j++){
//             if(this->hitBoxes[i]->checkCollision(otherCollision->hitBoxes[j])){
//                 return;
//             }
//         }
//     }

//     //cout << "OtherCollision" << endl;

//     for(int i = 0;i != otherCollision->hitBoxes.size();i++){
//         for(int j = 0;j != 3;j++){
//             //cout << otherCollision->hitBoxes.at(i)->position[j];
//             //if(j != 2) cout << ",";
//         }
//         //cout << endl;
//     }

//     //cout << endl;

//     //cout << "This" << endl;

//     for(int i = 0;i != otherCollision->hitBoxes.size();i++){
//         // if(i != 1)continue;
//         glm::vec3 defPosition =
//             this->hitBoxes.at(i)->position - otherCollision->hitBoxes.at(i)->position;


//         for(int j = 0;j != 3;j++){
//             //cout << this->hitBoxes.at(i)->position[j];


//             //if(j == 1)cout << ",";
//         }

//         //cout << endl << "DefPosition: " << i << endl;

//         for(int j = 0;j != 3;j++){
//             //cout << j << ": " << defPosition[j] << endl;
//         }

//         float xBorderDiff = defPosition[0] - dynamic_cast<HitBoxAABB*>(this->hitBoxes.at(i))->size[0] + 
//         dynamic_cast<HitBoxAABB*>(otherCollision->hitBoxes.at(i))->size[0];

//         //cout << 0 << ": " << xBorderDiff << endl;

//         if(xBorderDiff < 0 && xBorderDiff < (
//             dynamic_cast<HitBoxAABB*>(otherCollision->hitBoxes.at(i))->size[0]) + dynamic_cast<HitBoxAABB*>(this->hitBoxes.at(i))->size[0]){
//             //cout << "collision" << endl;
//         }
//     }
// }