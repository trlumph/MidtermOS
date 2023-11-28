cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME task4)
project(${PROJECT_NAME} C CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(load load.cpp)
