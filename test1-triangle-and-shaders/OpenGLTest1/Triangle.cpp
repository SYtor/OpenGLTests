//
// Created by syt0r on 9/21/19.
//

#include "Triangle.h"
#include "ShaderManager.h"
#include <random>

std::random_device randomDevice;
std::mt19937 mt(randomDevice());
std::uniform_real_distribution<float > distribution(0.0, 0.2);

Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3) {

    float vertices[] = {
            x1, y1,
            x2, y2,
            x3, y3
    };

    //VAO - Vertex Array Object

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //Prepare data

    //Coordinates

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);

    //Prepare shaders

    GLuint vertexShader = ShaderManager::LoadShader("shaders/testVertexShader.glsl", GL_VERTEX_SHADER);
    GLuint fragmentShader = ShaderManager::LoadShader("shaders/testFragmentShader.glsl", GL_FRAGMENT_SHADER);

    auto shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    GLint posAttr = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(posAttr, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(posAttr);

    valShaderAttrPointer = glGetUniformLocation(shaderProgram, "val");
    glUniform1f(valShaderAttrPointer, distribution(mt));

}


void Triangle::draw() {

    glBindVertexArray(vao);
    glUniform1f(valShaderAttrPointer, distribution(mt));
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

Triangle::~Triangle() {
    glDeleteBuffers(1, &vbo);
}
