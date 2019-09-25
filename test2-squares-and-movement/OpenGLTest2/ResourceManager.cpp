//
// Created by syt0r on 9/23/19.
//

#include "ResourceManager.h"

GLuint ResourceManager::loadTexture(std::string textureName) {

    GLuint textureReference;
    glGenTextures(1, &textureReference);
    glBindTexture(GL_TEXTURE_2D, textureReference);

    return -1;
}

void ResourceManager::unloadTexture(std::string textureName) {



}