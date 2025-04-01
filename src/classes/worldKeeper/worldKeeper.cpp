#include <classes/worldKeeper/worldKeeper.hpp>
#include <classes/extensions/extension.hpp>
#include <stdio.h>

void WorldKeeper::gameFrame(){

    for(int i = 0;i != this->entities.size();i++){
        for(int j = 0;j != this->entities[i]->extensionsNames.size();j++){
            // std::cout << this->entities[i]->extensionsNames[j] << std::endl;
            this->entities[i]->extensions[this->entities[i]->extensionsNames[j]]->gameFrame(this, i);
        }
    }
}