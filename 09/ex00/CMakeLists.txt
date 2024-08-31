cmake_minimum_required(VERSION 3.12) # version can be different

project(BitcoinExchange) #name of your project

set(SOURCE_FILES btc_test.cpp BitcoinExchange.cpp)
set(HEADER_FILES BitcoinExchange.hpp)

enable_testing() #to  discover tests in test explorer 

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(btc ${SOURCE_FILES} ${HEADER_FILES}) # add this executable

target_link_libraries(btc PRIVATE gtest) # link google test to this executable

include(GoogleTest)
gtest_discover_tests(btc) # discovers tests by asking the compiled test executable to enumerate its tests
