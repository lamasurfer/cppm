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

    try {
        Figure figure;
        print_info(&figure);
    }
    catch (const FigureParamsException& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << "\n\n";
    }

    try {
        Triangle triangle(10, 20, 30, 50, 60, 70);
        print_info(&triangle);
    }
    catch (const FigureParamsException& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << "\n\n";
    }

    try {
        RectangularTriangle rectangularTriangle(10, 20, 30, 50, 60);
        print_info(&rectangularTriangle);
    }
    catch (const FigureParamsException& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << "\n\n";
    }

    try {
        IsoscelesTriangle isoscelestriangle(10, 20, 50, 60);
        print_info(&isoscelestriangle);
    }
    catch (const FigureParamsException& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << "\n\n";
    }

    try {
        EquilateralTriangle equilateralRriangle(30);
        print_info(&equilateralRriangle);
    }
    catch (const FigureParamsException& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << "\n\n";
    }

    try {
        Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
        print_info(&quadrangle);
    }
    catch (const FigureParamsException& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << "\n\n";
    }

    try {
        Rectangle rectangle(10, 20);
        print_info(&rectangle);
    }
    catch (const FigureParamsException& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << "\n\n";
    }

    try {
        Square square(20);
        print_info(&square);
    }
    catch (const FigureParamsException& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << "\n\n";
    }

    try {
        Parallelogram parallelogram(20, 30, 30, 40);
        print_info(&parallelogram);
    }
    catch (const FigureParamsException& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << "\n\n";
    }

    try {
        //Rhombus rhombus(30, 30, 40);
        Rhombus rhombus(30, 30, 150);
        print_info(&rhombus);
    }
    catch (const FigureParamsException& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << "\n\n";
    }

    return 0;
}

void print_info(Figure* figure) {
    std::cout << figure->to_string() << " создан\n\n";
}