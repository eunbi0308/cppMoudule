cmake_minimum_required(VERSION 3.11)

# Project name
project(
    EUNBI
    LANGUAGES CXX
    VERSION 0.1
    DESCRIPTION "Trial")

add_executable (program main.cpp)

find_package(fmt REQUIRED)

target_link_libraries(program fmt::fmt)