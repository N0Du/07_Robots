cmake_minimum_required(VERSION 3.23)
project(Labo_07_Robots)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labo_07_Robots main.cpp robot.cpp robot.h terrain.cpp terrain.h annexe.h annexe.cpp position.h position.cpp)
