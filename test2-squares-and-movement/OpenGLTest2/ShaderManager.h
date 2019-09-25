//
// Created by syt0r on 9/23/19.
//

#ifndef TEST2_SQUARES_AND_TEXTURES_SHADERMANAGER_H
#define TEST2_SQUARES_AND_TEXTURES_SHADERMANAGER_H

#include <GL/glew.h>
#include <iostream>

class ShaderManager {

private:
    static std::string readFileToString(const std::string& fileName);

public:
    static GLuint LoadShader(const std::string& fileName, GLenum shaderType);

};

#endif //TEST2_SQUARES_AND_TEXTURES_SHADERMANAGER_H
