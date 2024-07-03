cmake_minimum_required(VERSION 3.28)
project(untitled)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
)
target_link_libraries(untitled ${OPENGL_LIBRARIES})
target_link_libraries(untitled ${GLUT_LIBRARIES})