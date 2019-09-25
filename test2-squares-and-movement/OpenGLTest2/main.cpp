#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include "Square.h"

void render();
void keyboardInput(unsigned char key, int x, int y);
void calculateFPS();

Square* square;

int main(int argc, char* argv[]) {

    glutInit(&argc, argv);
    glutInitContextVersion(4,0);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("Test");

    glutDisplayFunc(render);
    glutIdleFunc(render);
    glutKeyboardFunc(keyboardInput);

    glewInit();

    square = new Square();

    glutMainLoop();

    delete square;

    return 0;
}

void render() {

    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    square->render();

    glutSwapBuffers();

    calculateFPS();

}

void keyboardInput(unsigned char key, int x, int y) {

    printf("key presed: %i \n", key);

    switch(key) {
        case 'w':
            square->shiftPosition(0.0f, 0.1f);
            break;
        case 's':
            square->shiftPosition(0.0f, -0.1f);
            break;
        case 'a':
            square->shiftPosition(-0.1f, 0);
            break;
        case 'd':
            square->shiftPosition(0.1f, 0);
            break;
    }

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

