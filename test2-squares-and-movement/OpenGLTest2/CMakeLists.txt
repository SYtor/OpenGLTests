cmake_minimum_required(VERSION 3.14)
project(OpenGLTest2)

set(CMAKE_CXX_STANDARD 17)

add_executable(OpenGLTest2 main.cpp Square.cpp Square.h ResourceManager.cpp ResourceManager.h ShaderManager.cpp ShaderManager.h)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} )
target_link_libraries(OpenGLTest2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY} )
