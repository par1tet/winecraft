#include <glad/glad.h>
#include <glm/glm.hpp>
#include <cube.hpp>
#include <entity.hpp>
#include <vector>

using namespace std;

int width = 800, height = 600;

int targetFps = 60;
float sizeCube = 1.0f;

vector<Entity> entitiesList = {
    new Cube(glm::vec3(0.0f, 0.0f, 0.0f), "assets/textures/murych_cat", 1.0f),
    new Cube(glm::vec3(1.0f, 1.0f, 0.0f), "assets/textures/murych_cat", 1.0f),
};

GLfloat vertices[] {
    -sizeCube, -sizeCube, -sizeCube,
     sizeCube, -sizeCube, -sizeCube,
     sizeCube,  sizeCube, -sizeCube,
     sizeCube,  sizeCube, -sizeCube,
    -sizeCube,  sizeCube, -sizeCube,
    -sizeCube, -sizeCube, -sizeCube,

    -sizeCube, -sizeCube,  sizeCube,
     sizeCube, -sizeCube,  sizeCube,
     sizeCube,  sizeCube,  sizeCube,
     sizeCube,  sizeCube,  sizeCube,
    -sizeCube,  sizeCube,  sizeCube,
    -sizeCube, -sizeCube,  sizeCube,

    -sizeCube,  sizeCube,  sizeCube,
    -sizeCube,  sizeCube, -sizeCube,
    -sizeCube, -sizeCube, -sizeCube,
    -sizeCube, -sizeCube, -sizeCube,
    -sizeCube, -sizeCube,  sizeCube,
    -sizeCube,  sizeCube,  sizeCube,

     sizeCube,  sizeCube,  sizeCube,
     sizeCube,  sizeCube, -sizeCube,
     sizeCube, -sizeCube, -sizeCube,
     sizeCube, -sizeCube, -sizeCube,
     sizeCube, -sizeCube,  sizeCube,
     sizeCube,  sizeCube,  sizeCube,

    -sizeCube, -sizeCube, -sizeCube,
     sizeCube, -sizeCube, -sizeCube,
     sizeCube, -sizeCube,  sizeCube,
     sizeCube, -sizeCube,  sizeCube,
    -sizeCube, -sizeCube,  sizeCube,
    -sizeCube, -sizeCube, -sizeCube,

    -sizeCube,  sizeCube, -sizeCube,
     sizeCube,  sizeCube, -sizeCube,
     sizeCube,  sizeCube,  sizeCube,
     sizeCube,  sizeCube,  sizeCube,
    -sizeCube,  sizeCube,  sizeCube,
    -sizeCube,  sizeCube, -sizeCube,
};

GLfloat texCoords[] {
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 0.0f,

    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f,

    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 0.0f,
};