//
// Created by syt0r on 9/23/19.
//

#include "Square.h"
#include "ShaderManager.h"

Square::Square() {

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

    GLuint vertexShader = ShaderManager::LoadShader("shaders/textureShaderVertex.glsl", GL_VERTEX_SHADER);
    GLuint fragmentShader = ShaderManager::LoadShader("shaders/textureShaderFragment.glsl", GL_FRAGMENT_SHADER);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    GLint posAttr = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(posAttr, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(posAttr);

    transform = glm::mat4(1.0f);
    transformUniformLocation = glGetUniformLocation(shaderProgram, "transform");
    glUniformMatrix4fv(transformUniformLocation, 1, GL_FALSE, glm::value_ptr(transform));

}

Square::~Square() {
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(shaderProgram);
}

void Square::render() {

    glBindVertexArray(vao);
    glUniformMatrix4fv(transformUniformLocation, 1, GL_FALSE, glm::value_ptr(transform));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

}

void Square::shiftPosition(float x, float y) {
    transform = glm::translate(transform, glm::vec3(x, y, 0.0f));
}