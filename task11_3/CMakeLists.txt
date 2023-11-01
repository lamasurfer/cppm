cmake_minimum_required(VERSION 3.16)
project(leaver_cmake_shared)

set(LEAVER_SHARED_LIB leaver.cpp leaver.h)
add_library(leaver_shared_lib SHARED ${LEAVER_SHARED_LIB})

set(LEAVER_EXEC leaver_shared_client.cpp)
add_executable(leaver_cmake_shared ${LEAVER_EXEC})

target_link_libraries(leaver_cmake_shared leaver_shared_lib)