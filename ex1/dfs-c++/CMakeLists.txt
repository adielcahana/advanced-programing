cmake_minimum_required(VERSION 3.6)
project(dfs-c++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Binary_tree.cpp Binary_tree.h)
add_executable(dfs-c++ ${SOURCE_FILES})