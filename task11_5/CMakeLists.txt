cmake_minimum_required(VERSION 3.16)
project(figure_cmake_shared)

set(FIGURE_SHARED_LIB
    Figure.cpp Figure.h
    Triangle.cpp Triangle.h
    EquilateralTriangle.cpp EquilateralTriangle.h
    IsoscelesTriangle.cpp IsoscelesTriangle.h
    RectangularTriangle.cpp RectangularTriangle.h
    Quadrangle.cpp Quadrangle.h
    Rectangle.cpp Rectangle.h
    Parallelogram.cpp Parallelogram.h
    Rhombus.cpp Rhombus.h
    Square.cpp Square.h
)

add_library(figure_shared_lib SHARED ${FIGURE_SHARED_LIB})

set(FIGURE_EXEC figure_cmake_client.cpp)
add_executable(figure_cmake_shared ${FIGURE_EXEC})

target_link_libraries(figure_cmake_shared figure_shared_lib)