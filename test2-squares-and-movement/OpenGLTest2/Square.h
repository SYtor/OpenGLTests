//
// Created by syt0r on 9/23/19.
//

#ifndef TEST2_SQUARES_AND_TEXTURES_SQUARE_H
#define TEST2_SQUARES_AND_TEXTURES_SQUARE_H

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Square {

private:

    float vertexes[8] = {
        0.5, 0.5,
        -0.5, 0.5,
        -0.5, -0.5,
        0.5, -0.5
    };

    glm::mat4 transform;

    GLuint vao;
    GLuint vbo;
    GLuint ebo;
    GLuint shaderProgram;
    GLuint transformUniformLocation;

public:
    Square();
    ~Square();
    void render();
    void shiftPosition(float x, float y);

};

#endif //TEST2_SQUARES_AND_TEXTURES_SQUARE_H
