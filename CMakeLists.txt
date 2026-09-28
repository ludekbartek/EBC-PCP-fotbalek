cmake_minimum_required(VERSION 4.0)
project(fotbalek)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(fotbalek
        .idea/.gitignore
        .idea/fotbalek.iml
        .idea/modules.xml
        Dictionary.cpp
        Dictionary.h
        Game.cpp
        Game.h
        main.cpp)
