cmake_minimum_required(VERSION 3.13)
project(myCourse)

set(CMAKE_CXX_STANDARD 14)

add_executable(myCourse measurement.h measurement.c array_sort.h array_sort.c vector_sort.h menu.h menu.c vector_sort.c common.h common.c main.c)