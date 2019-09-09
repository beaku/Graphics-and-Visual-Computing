cmake_minimum_required(VERSION 3.14)
project(Lab_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_3 main.cpp)

set(OpenGlLinkers -lglut -lGLU -lGL) # setting all the Glut libraries as one variable.


################################################

target_link_libraries(Lab_3 ${OpenGlLinkers}) # linking opengl libraries to the project