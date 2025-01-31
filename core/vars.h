#include <glad/glad.h>
#include <glm/glm.hpp>

int width = 800, height = 600;

int targetFps = 60;
float sizeCube = 1.0f;

float cubeSizes[] = {1.0f, 0.5f};

glm::vec3 cubePositions[] = {
    glm::vec3( -1.0f,  -1.5f,  0.0f), 
    glm::vec3( 1.0f,  3.0f,  0.0f), 
};

GLfloat vertices[] = {
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

GLfloat texCoords[] = {
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

GLuint indices[] = {
    0, 1, 3,
    1, 2, 3
};