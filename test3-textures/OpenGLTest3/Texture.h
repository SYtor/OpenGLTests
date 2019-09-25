//
// Created by syt0r on 9/25/19.
//

#ifndef OPENGLTEST3_TEXTURE_H
#define OPENGLTEST3_TEXTURE_H

#include <GL/glew.h>

class Texture {

private:
    GLuint texture;

public:
    Texture(const char* fileName);
    ~Texture();

    GLuint getTexture() { return texture; }

};


#endif //OPENGLTEST3_TEXTURE_H
