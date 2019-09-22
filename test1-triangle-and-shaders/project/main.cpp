#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Actor.h"
#include "Triangle.h"
#include <vector>
#include <random>

void initActors();
void clearActorResources();
void render();

std::vector<Actor*> actors;

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

    clearActorResources();

    return 0;
}

void initActors() {

    std::random_device randomDevice;
    std::mt19937 mt(randomDevice());
    std::uniform_real_distribution<float > distribution(-1.0, 1.0);

    for(int i = 0; i < 10; i++)
        actors.push_back(new Triangle(
                distribution(randomDevice),
                distribution(randomDevice),
                distribution(randomDevice),
                distribution(randomDevice),
                distribution(randomDevice),
                distribution(randomDevice)
                ));

}

void clearActorResources() {

    for(Actor* actor : actors) {
        delete actor;
    }

}

void render() {

    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

    for(Actor* actor : actors) {
        actor->draw();
    }

    glutSwapBuffers();

}