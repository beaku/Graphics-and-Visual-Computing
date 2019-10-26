cmake_minimum_required(VERSION 3.14)
project(Lab_6)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_6 main.cpp fracviewer.c fracviewer.c fracviewer.h)

set(OpenGlLinkers -lGL -lGLU -lX11 -lglut -lm) # setting all the Glut libraries as one variable.
set(SDLLinkers -lSDL2 -lm)

target_link_libraries(Lab_6 ${OpenGlLinkers}) # linking opengl libraries to the project