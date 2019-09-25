//
// Created by syt0r on 9/25/19.
//

#include "Shader.h"
#include <fstream>

Shader::Shader(const char *vertexShaderFile, const char *fragmentShaderFile) {

    auto vertexScript = readFile(vertexShaderFile);
    auto fragmentScript = readFile(fragmentShaderFile);

    GLuint vertexShader = compileShader(vertexScript, GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(fragmentScript, GL_FRAGMENT_SHADER);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

}

Shader::~Shader() {
    glDeleteProgram(shaderProgram);
}

std::string Shader::readFile(const std::string& fileName) {

    std::ifstream file(fileName);

    if(!file.is_open())
        throw std::invalid_argument("File " + fileName + " not found");

    std::string contents((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());

    return contents;
}

GLuint Shader::compileShader(const std::string& shaderScript, GLenum shaderType) {

    auto script = shaderScript.c_str();

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &script, nullptr);
    glCompileShader(shader);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if(status != GL_TRUE) {
        char buffer[512];
        glGetShaderInfoLog(shader, 512, nullptr, buffer);
        throw std::runtime_error(buffer);
    }

    return shader;
}