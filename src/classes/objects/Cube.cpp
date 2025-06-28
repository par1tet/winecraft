#include<glad/glad.h>
#include<classes/objects/cube.hpp>

Cube::Cube(glm::vec3 position, std::string texturePath, glm::vec3 size) : Object(position, texturePath){
    this->size = size;
}

glm::vec3 Cube::getSize(){
    return size;
}

void Cube::drawObject(GLuint shaderProgram){
    GLuint VAO, VBO, EBO, TBO;

    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &TBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, TBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, TBO);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(1);

    GLuint texture = loadTexture(getAssetPath("textures/murych_cat.png").c_str());

    GLuint colorLocation = glGetUniformLocation(shaderProgram, "colorCube");
    GLuint sizeLocation = glGetUniformLocation(shaderProgram, "sizeCube");

    glUseProgram(shaderProgram);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBindVertexArray(VAO);
    
    float color[] = {1.f, 1.0f, 1.0f, 1.0f};

    glUniform4fv(colorLocation, 1, color);
    glUniform3fv(sizeLocation, 1, glm::value_ptr(this->size/2.f));

    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindVertexArray(0);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}