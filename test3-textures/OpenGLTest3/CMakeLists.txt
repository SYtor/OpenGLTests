cmake_minimum_required(VERSION 3.14)
project(OpenGLTest3)

set(CMAKE_CXX_STANDARD 17)

add_executable(OpenGLTest3 main.cpp Sprite.cpp Sprite.h Shader.cpp Shader.h FPSCounter.cpp FPSCounter.h Texture.cpp Texture.h stb_image.h stb_image.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} )
target_link_libraries(OpenGLTest3 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY} )