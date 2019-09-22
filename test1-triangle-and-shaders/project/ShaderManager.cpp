//
// Created by syt0r on 9/21/19.
//

#include "ShaderManager.h"
#include <fstream>

std::string ShaderManager::readFileToString(const std::string& fileName) {

    std::ifstream file(fileName);

    if(!file.is_open())
        throw std::invalid_argument("File " + fileName + " not found");

    std::string contents((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());

    return contents;
}

GLuint ShaderManager::LoadShader(const std::string& fileName, GLenum shaderType) {

    //Load and Compile Shader

    auto shaderScript = readFileToString(fileName);
    auto constScript = shaderScript.c_str();
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &constScript, nullptr);
    glCompileShader(shader);

    //Check compile status

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if(status != GL_TRUE) {
        char buffer[512];
        glGetShaderInfoLog(shader, 512, nullptr, buffer);
        throw std::runtime_error("Could load shader " + fileName + " " + buffer);
    }

    return shader;
}
