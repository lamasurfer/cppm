cmake_minimum_required(VERSION 3.16)
project(my_first_cmake_project)

set(FIRST_EXEC main.cpp)

add_executable(my_first_cmake_program ${FIRST_EXEC})
