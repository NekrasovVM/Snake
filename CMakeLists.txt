cmake_minimum_required(VERSION 3.10)

project(Snake VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(SnakeConfig.h.in SnakeConfig.h)

add_executable(Snake main.cpp Field.cpp  Game.cpp Snake.cpp)

target_include_directories(Snake PUBLIC "${PROJECT_BINARY_DIR}")
