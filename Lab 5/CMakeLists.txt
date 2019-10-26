cmake_minimum_required(VERSION 3.14)
project(Lab_5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_5 main.cpp bezeir.cpp circle.cpp main2.cpp)

set(OpenGlLinkers -lglut -lGLU -lGL) # setting all the Glut libraries as one variable.
set(SDLLinkers -lSDL2 -lm)

target_link_libraries(Lab_5 ${OpenGlLinkers}) # linking opengl libraries to the project
target_link_libraries(Lab_5 ${SDLLinkers})