cmake_minimum_required(VERSION 3.12) # version can be different

project(RPN) #name of your project

set(SOURCE_FILES RPN_test.cpp RPN.cpp)
set(HEADER_FILES RPN.hpp)

enable_testing() #to  discover tests in test explorer 

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(RPN ${SOURCE_FILES} ${HEADER_FILES}) # add this executable

target_link_libraries(RPN PRIVATE gtest) # link google test to this executable

include(GoogleTest)
gtest_discover_tests(RPN) # discovers tests by asking the compiled test executable to enumerate its tests