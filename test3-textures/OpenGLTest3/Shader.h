//
// Created by syt0r on 9/25/19.
//

#ifndef OPENGLTEST3_SHADER_H
#define OPENGLTEST3_SHADER_H

#include <string>
#include <GL/glew.h>

class Shader {

private:

    GLuint shaderProgram;

    static std::string readFile(const std::string& fileName);
    static GLuint compileShader(const std::string& shaderScript, GLenum shaderType);

public:

    Shader(const char* vertexShaderFile, const char* fragmentShaderFile);
    ~Shader();

    GLuint getShaderProgram() { return shaderProgram; }

};


#endif //OPENGLTEST3_SHADER_H
