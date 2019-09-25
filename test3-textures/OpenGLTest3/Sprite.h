//
// Created by syt0r on 9/25/19.
//

#ifndef OPENGLTEST3_SPRITE_H
#define OPENGLTEST3_SPRITE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "Texture.h"

class Sprite {

private:

    glm::mat4 transform;

    GLuint vao;
    GLuint vbo;
    GLuint ebo;
    GLuint transformUniformLocation;

    Shader* shader;
    Texture* texture;

public:
    Sprite(const char* textureFilePath);
    ~Sprite();
    void render();
};


#endif //OPENGLTEST3_SPRITE_H
