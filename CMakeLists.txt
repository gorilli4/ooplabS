cmake_minimum_required(VERSION 3.14)

project(lab_5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SOURCES "include/*.hpp")

add_executable(lab_5 main.cpp ${SOURCES})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(lab_5tests test/test.cpp ${SOURCES})

target_link_libraries(lab_5tests gtest_main)

add_test(NAME lab_5tests COMMAND lab_5tests)