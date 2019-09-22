#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <random>
#include "Triangle.h"

void initActors();
void render();

std::vector<Triangle> triangles;

int main(int argc, char* argv[]) {

    glutInit(&argc, argv);
    glutInitContextVersion(4,0);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("Test");

    glutIdleFunc(render);
    glutDisplayFunc(render);

    glewInit();

    initActors();

    glutMainLoop();

    return 0;
}

void initActors() {

    std::random_device randomDevice;
    std::mt19937 mt(randomDevice());
    std::uniform_real_distribution<float > distribution(-1.0, 1.0);

    for(int i = 0; i < 10; i++)
        triangles.emplace_back(
                distribution(randomDevice),
                distribution(randomDevice),
                distribution(randomDevice),
                distribution(randomDevice),
                distribution(randomDevice),
                distribution(randomDevice)
                );

}

void render() {

    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

    for(Triangle t : triangles)
        t.draw();

    glutSwapBuffers();

}