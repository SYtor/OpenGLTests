//
// Created by syt0r on 9/21/19.
//

#ifndef OPENGLTEST_ACTOR_H
#define OPENGLTEST_ACTOR_H

class Actor {

private:
    float x;
    float y;
    float width;
    float height;

public:

    float getX() const {
        return x;
    }

    void setX(float x) {
        Actor::x = x;
    }

    float getY() const {
        return y;
    }

    void setY(float y) {
        Actor::y = y;
    }

    float getWidth() const {
        return width;
    }

    void setWidth(float width) {
        Actor::width = width;
    }

    float getHeight() const {
        return height;
    }

    void setHeight(float height) {
        Actor::height = height;
    }

    Actor() {}
    virtual ~Actor() {}
    virtual void draw() = 0;

};

#endif //OPENGLTEST_ACTOR_H
