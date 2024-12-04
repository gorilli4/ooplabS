cmake_minimum_required(VERSION 3.10)

project(oop1lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop1lab main.cpp days_to_reach_height.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests tests.cpp days_to_reach_height.cpp)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

enable_testing()
add_test(NAME runTests COMMAND runTests)