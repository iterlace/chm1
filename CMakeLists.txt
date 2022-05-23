cmake_minimum_required(VERSION 3.21)
project(chm1)

set(CMAKE_CXX_STANDARD 23)

add_executable(dichotomy dichotomy.cpp)
add_executable(relaxation relaxation.cpp)
add_executable(iteration iteration.cpp)
