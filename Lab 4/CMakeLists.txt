cmake_minimum_required(VERSION 3.14)
project(Lab_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_4 main.cpp)

set(OpenGlLinkers -lglut -lGLU -lGL) # setting all the Glut libraries as one variable.


################################################

target_link_libraries(Lab_4 ${OpenGlLinkers}) # linking opengl libraries to the project