//
// Created by syt0r on 9/23/19.
//

#ifndef TEST2_SQUARES_AND_TEXTURES_RESOURCEMANAGER_H
#define TEST2_SQUARES_AND_TEXTURES_RESOURCEMANAGER_H

#include <GL/glew.h>
#include <string>

#include <unordered_map>
#include <utility>

class ResourceManager {

private:
    //                          Texture           Reference  Num of usages
    static std::unordered_map<std::string, std::pair<GLuint, int>> textureStorage;

public:
    static GLuint loadTexture(std::string textureName);
    static void unloadTexture(std::string textureName);

};


#endif //TEST2_SQUARES_AND_TEXTURES_RESOURCEMANAGER_H
