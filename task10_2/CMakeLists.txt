cmake_minimum_required(VERSION 3.16)
project(Figures)

set(SOURCE
    task10_2.cpp
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

add_executable(Figures ${SOURCE})