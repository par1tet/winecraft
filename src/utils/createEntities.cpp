#include <vector>
#include <classes/objects/object.hpp>
#include <string>
#include <classes/hitBoxes/collision.hpp>
#include <classes/entities/entity.hpp>
#include <classes/extensions/position.hpp>
#include <classes/extensions/object.hpp>
#include <classes/objects/cube.hpp>

std::vector<Object*> createCubeObjects(std::vector<glm::vec3> positions, std::vector<glm::vec3> sizes){
    std::vector<Object*> cubes;

    for(int i = 0;i != positions.size();i++){
        cubes.push_back(new Cube(positions[i], "assets/textures/murych_cat.png", sizes[i]));
    }

    return cubes;
}

std::vector<Object*> createCubeObjects(std::vector<glm::vec3> positions, std::vector<glm::vec3> sizes, std::vector<std::string> textures){
    std::vector<Object*> cubes;

    for(int i = 0;i != positions.size();i++){
        cubes.push_back(new Cube(positions[i], textures[i], sizes[i]));
    }

    return cubes;
}

Collision* createCollisionHitBoxAABB(std::vector<glm::vec3> positionsHitBoxesAABB, std::vector<glm::vec3> sizesHitBoxesAABB){
    std::vector<HitBox*> hitBoxes;

    for(int i = 0;i != positionsHitBoxesAABB.size();i++){
        hitBoxes.push_back(new HitBoxAABB(positionsHitBoxesAABB[i], sizesHitBoxesAABB[i]));
    }

    return (new Collision(hitBoxes));
}

Entity* createCube(glm::vec3 position, glm::vec3 size, std::string texturePath){
    Entity* cube = new Entity(new Collision(std::vector<HitBox*>{new HitBoxAABB(position, size)}), {new ObjectExtension(std::vector<Object*>{new Cube(glm::vec3(0.0f), texturePath, size)}), new Position(position)});

    return cube;
}

Entity* createCube(glm::vec3 position, glm::vec3 size){
    Entity* cube = new Entity(new Collision(std::vector<HitBox*>{new HitBoxAABB(position, size)}), {new ObjectExtension(std::vector<Object*>{new Cube(glm::vec3(0.0f), "assets/textures/murych_cat.png", size)}), new Position(position)});

    return cube;
}

Entity* createCube(glm::vec3 position){
    Entity* cube = new Entity(new Collision(std::vector<HitBox*>{new HitBoxAABB(position, glm::vec3(1.0f))}), {new ObjectExtension(std::vector<Object*>{new Cube(glm::vec3(0.0f),"assets/textures/murych_cat.png", glm::vec3(1.0f))}), new Position(position)});

    return cube;
}

Entity* createCube(glm::vec3 position, std::string texturePath){
    Entity* cube = new Entity(new Collision(std::vector<HitBox*>{new HitBoxAABB(position, glm::vec3(1.0f))}), {new ObjectExtension(std::vector<Object*>{new Cube(glm::vec3(0.0f), texturePath, glm::vec3(1.0f))}), new Position(position)});

    return cube;
}