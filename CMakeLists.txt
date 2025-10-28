cmake_minimum_required(VERSION 4.0)
project(tp3)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(tp3
        main.cpp
        Grille.cpp
        Grille.hpp
)
