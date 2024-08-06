cmake_minimum_required(VERSION 3.27)
project(Data_Structure)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Data_Structure
        AVL_Tree.h
        linkedList.h
        pirate.cpp
        pirate.h
        pirates24b1.cpp
        pirates24b1.h
        ship.cpp
        ship.h
        wet1util.h
        main.cpp)
