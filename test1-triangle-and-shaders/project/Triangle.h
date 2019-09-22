//
// Created by syt0r on 9/21/19.
//

#ifndef OPENGLTEST_TRIANGLE_H
#define OPENGLTEST_TRIANGLE_H

#include <GL/glew.h>
#include "Actor.h"

class Triangle : public Actor {

private:
    GLuint vao;
    GLint kek = 0;

public:
    Triangle() : Triangle(0,0,0,0,0,0) {}
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
    ~Triangle();
    void draw();

};


#endif //OPENGLTEST_TRIANGLE_H
