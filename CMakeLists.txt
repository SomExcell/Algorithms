cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

set(PROJECT_NAME algorithms)

include_directories("header/")

set(SOURCES source/main.cpp)

set (HEADERS header/algorithms.hpp)

add_executable(algorithms ${SOURCES} ${HEADERS})
