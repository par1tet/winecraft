#include<classes/extensions/position.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<stdio.h>

void Position::gameFrame(WorldKeeper* worldKeeperCl, int enId){
    std::cout << "x: " << this->position.x << " y: " << this->position.y << " z: " << this->position.z << std::endl;
}