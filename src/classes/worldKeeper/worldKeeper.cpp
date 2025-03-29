#include <classes/worldKeeper/worldKeeper.hpp>
#include <stdio.h>

void WorldKeeper::gameFrame(){
    std::cout << "penis" << std::endl;

    for(int i = 0;i != this->entities.size();i++){
        for(int j = 0;j != this->entities[i]->extensions.size();j++){
            this->entities[i]->extensions[j]->gameFrame();
        }
    }
}