cmake_minimum_required(VERSION 3.15)
project(pro_lab4 C)

set(CMAKE_C_STANDARD 99)

add_executable(pro_lab4 main.c)

target_link_libraries(pro_lab4 pthread)