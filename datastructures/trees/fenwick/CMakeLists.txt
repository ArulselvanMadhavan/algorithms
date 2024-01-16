cmake_minimum_required(VERSION 3.22)
project(fenwick)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(fenwick main.cpp)
set_property(TARGET fenwick PROPERTY CXX_STANDARD 20)

