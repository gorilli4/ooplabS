cmake_minimum_required(VERSION 3.10)
project(lab_2)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
        TLS_VERIFY false
)

FetchContent_MakeAvailable(googletest)

# Добавляем библиотеку для решения
add_library(lab_2_lib src/Octal.cpp)

# Включаем директорию с заголовочными файлами
target_include_directories(lab_2_lib PUBLIC include)

# Создание основного исполняемого файла
add_executable(lab_2_exe main.cpp)

# Линковка библиотеки с исполняемым файлом
target_link_libraries(lab_2_exe PRIVATE lab_2_lib)

# Включаем поддержку тестов
enable_testing()

# Создание тестов
add_executable(lab_2_tests tests/test01.cpp)

# Линковка тестов с библиотекой и Google Test
target_link_libraries(lab_2_tests lab_2_lib gtest_main)

# Добавление тестов в набор тестирования
add_test(NAME TestLab2 COMMAND lab_2_tests)

# Добавляем тест в CTest
add_test(NAME MyTests COMMAND runTests)