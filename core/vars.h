#include <glad/glad.h>

int width = 800, height = 600;

int targetFps = 60;
float sizeCube = 0.6f;

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
    0.0f, 1.0f
};

GLuint indices[] = {
    0, 1, 3,
    1, 2, 3,
};