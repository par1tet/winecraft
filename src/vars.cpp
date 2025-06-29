#include<vars.hpp>

int width = 800, height = 600;

int targetFps = 60;
float sizeCube = 1.0f;

GLfloat vertices[] = {
    -sizeCube, -sizeCube, -sizeCube,
    sizeCube, -sizeCube, -sizeCube,
    sizeCube,  sizeCube, -sizeCube,
    -sizeCube,  sizeCube, -sizeCube,
    -sizeCube, -sizeCube,  sizeCube,
    sizeCube, -sizeCube,  sizeCube,
    sizeCube,  sizeCube,  sizeCube,
    -sizeCube,  sizeCube,  sizeCube
};

GLuint indeces[] = {
    0, 1, 2, 2, 3, 0,
    4, 5, 6, 6, 7, 4,
    0, 3, 7, 7, 4, 0,
    1, 5, 6, 6, 2, 1,
    0, 1, 5, 5, 4, 0,
    3, 2, 6, 6, 7, 3
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