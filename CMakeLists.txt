cmake_minimum_required(VERSION 4.0)
project(Pipod)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pipod main.cpp
        model/MediaManager.cpp
        model/MediaManager.hpp)
