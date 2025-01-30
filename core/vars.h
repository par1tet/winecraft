#include <glad/glad.h>

int width = 800, height = 600;

int targetFps = 60;

GLfloat texCoords[] = {
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,
};

GLfloat vertices[] = {
    0.27625f,  0.36f, 0.0f,
    0.27625f, -0.36f, 0.0f,
    -0.27625f, -0.36f, 0.0f,
    -0.27625f, 0.36f, 0.0f, 
};

GLfloat colors[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 0.0f,
};

GLuint indices[] = {
    0, 1, 3,
    1, 2, 3,
};