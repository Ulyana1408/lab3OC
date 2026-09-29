cmake_minimum_required(VERSION 3.15)
project(Lab3_UnitTests CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Наша библиотека с функцией linear_interp
add_library(math_func STATIC src/math_func.cpp)
target_include_directories(math_func PUBLIC src)

# 2. Тесты Catch2 (у нас уже есть catch.hpp)
add_executable(test_catch2 tests_catch2/test_catch2.cpp)
target_include_directories(test_catch2 PRIVATE tests_catch2)
target_link_libraries(test_catch2 PRIVATE math_func)

# Google Test — скачиваем через FetchContent
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 4. Тесты Google Test
add_executable(test_gtest tests_gtest/test_gtest.cpp)
target_link_libraries(test_gtest PRIVATE math_func gtest_main)


# 5. Включаем автообнаружение тестов через CTest (опционально)
enable_testing()
add_test(NAME Catch2Tests COMMAND test_catch2)
add_test(NAME GTestTests  COMMAND test_gtest)