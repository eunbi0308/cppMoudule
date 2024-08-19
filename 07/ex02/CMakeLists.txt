cmake_minimum_required(VERSION 3.11)

# Project name
project(
    Array
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

# Conditional compilation flags
if(DEBUG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fsanitize=address -g")
elseif(STRUCTOR)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g -DSTRUCTOR")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

set(SOURCE_FILES main.cpp)
set(HEADER_FILES Array.hpp Array.tpp)

add_executable (Array ${SOURCE_FILES} ${HEADER_FILES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(fmt REQUIRED)

target_link_libraries(Array fmt::fmt)