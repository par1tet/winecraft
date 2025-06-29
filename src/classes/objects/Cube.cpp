#include<glad/glad.h>
#include<classes/objects/cube.hpp>

bool Cube::generatedBuffers = false;
GLuint Cube::VAO = 0;
GLuint Cube::VBO = 0;
GLuint Cube::EBO = 0;
GLuint Cube::TBO = 0;

Cube::Cube(glm::vec3 position, std::string texturePath, glm::vec3 size) : Object(position, texturePath){
    this->size = size;

    this->texture = loadTexture(getAssetPath("textures/murych_cat.png").c_str());

    if(!generatedBuffers){
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        glGenBuffers(1, &TBO);
        
        glBindVertexArray(VAO);
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, TBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW); 

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, TBO);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);
        generatedBuffers = true;
    }
}

glm::vec3 Cube::getSize(){
    return size;
}

void Cube::drawObject(GLuint shaderProgram){
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);

    GLuint colorLocation = glGetUniformLocation(shaderProgram, "colorCube");
    GLuint sizeLocation = glGetUniformLocation(shaderProgram, "sizeCube");

    glBindTexture(GL_TEXTURE_2D, this->texture);
    
    float color[] = {1.f, 1.0f, 1.0f, 1.0f};

    glUniform4fv(colorLocation, 1, color);
    glUniform3fv(sizeLocation, 1, glm::value_ptr(this->size/2.f));

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}