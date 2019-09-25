#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include "Sprite.h"

void render();
void calculateFPS();

Sprite *sprite;

int main(int argc, char* argv[]) {

    glutInit(&argc, argv);
    glutInitContextVersion(4,0);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("Test");

    glutDisplayFunc(render);
    glutIdleFunc(render);

    glewInit();

    sprite = new Sprite("textures/dinosaur.png");

    glutMainLoop();

    delete sprite;

    return 0;
}

void render() {

    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    sprite->render();

    glutSwapBuffers();

    calculateFPS();

}

int framesCount = 0, lastTimeFpsCount = 0;
char title[220];
void calculateFPS() {

    framesCount++;

    int currentTime = glutGet(GLUT_ELAPSED_TIME);

    if (currentTime - lastTimeFpsCount > 1000) {

        float fps = framesCount * 1000.0f / (currentTime - lastTimeFpsCount);
        lastTimeFpsCount = currentTime;
        framesCount = 0;

        sprintf(title, "OpenGLTest, FPS = %4.2f", fps);
        glutSetWindowTitle(title);

    }

}
