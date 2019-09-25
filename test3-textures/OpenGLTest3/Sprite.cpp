//
// Created by syt0r on 9/25/19.
//

#include "Sprite.h"

Sprite::Sprite(const char *textureFilePath) {

    float vertexes[] = {
            //Vertices      //Texture Coords
            -0.5, -0.5,     0,0,
            0.5, -0.5,      1,0,
            0.5, 0.5,       1,1,
            -0.5, 0.5,      0,1
    };

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), &vertexes, GL_DYNAMIC_DRAW);

    GLuint elements[] = {
            0, 1, 2, //First Triangle
            2, 3, 0  // Second Triangle
    };

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), &elements, GL_DYNAMIC_DRAW);

    shader = new Shader("shaders/vertexShader.glsl","shaders/fragmentShader.glsl");
    auto shaderProgram = shader->getShaderProgram();
    glUseProgram(shaderProgram);

    GLint posAttr = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(posAttr, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
    glEnableVertexAttribArray(posAttr);

    GLint texCoordAttr = glGetAttribLocation(shaderProgram, "texture_coordinate");
    glVertexAttribPointer(texCoordAttr, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(texCoordAttr);

    transform = glm::mat4(1.0f);
    transformUniformLocation = glGetUniformLocation(shaderProgram, "transform");
    glUniformMatrix4fv(transformUniformLocation, 1, GL_FALSE, glm::value_ptr(transform));

    texture = new Texture(textureFilePath);
    glUniform1i(glGetUniformLocation(texture->getTexture(), "texture"), 0);

}

Sprite::~Sprite() {
    delete shader;
    delete texture;
}

void Sprite::render() {

    transform = glm::rotate(transform, glm::radians(0.1f), glm::vec3(0,1,0));

    glBindVertexArray(vao);
    glUniformMatrix4fv(transformUniformLocation, 1, GL_FALSE, glm::value_ptr(transform));
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, texture->getTexture());
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

}
