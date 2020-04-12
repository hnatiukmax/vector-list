cmake_minimum_required(VERSION 3.14)
project(vector_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(vector_list main.cpp vector/Vector.cpp vector/Vector.h)