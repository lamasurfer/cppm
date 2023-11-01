#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "RectangularTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrangle.h"
#include "Rectangle.h"
#include "Parallelogram.h"
#include "Rhombus.h"
#include "Square.h"

void print_info(Figure* figure);

int main() {

    setlocale(LC_ALL, "rus");

    Figure figure;
    print_info(&figure);
    
    Triangle triangle(10, 20, 30, 50, 60, 70);
    print_info(&triangle);
    
    RectangularTriangle rectangularTriangle(10, 20, 30, 50, 60);
    print_info(&rectangularTriangle);

    IsoscelesTriangle isoscelestriangle(10, 20, 50, 60);
    print_info(&isoscelestriangle);

    EquilateralTriangle equilateralRriangle(30);
    print_info(&equilateralRriangle);

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    print_info(&quadrangle);

    Rectangle rectangle(10, 20);
    print_info(&rectangle);

    Square square(20);
    print_info(&square);

    Parallelogram parallelogram(20, 30, 30, 40);
    print_info(&parallelogram);

    Rhombus rhombus(30, 30, 40);
    print_info(&rhombus);
    
    return 0;
}

void print_info(Figure* figure) {
    std::cout << figure->to_string() << "\n";
}