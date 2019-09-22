//
// Created by syt0r on 9/21/19.
//

#ifndef OPENGLTEST_SHADERMANAGER_H
#define OPENGLTEST_SHADERMANAGER_H

#include <GL/glew.h>
#include <iostream>

class ShaderManager {

private:
    static std::string readFileToString(const std::string& fileName);

public:
    static GLuint LoadShader(const std::string& fileName, GLenum shaderType);

};


#endif //OPENGLTEST_SHADERMANAGER_H
