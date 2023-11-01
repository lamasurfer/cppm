#include "Rectangle.h"

Rectangle::Rectangle(std::string name, int a, int b) : Parallelogram(name, a, b, 90, 90) {}
Rectangle::Rectangle(int a, int b) : Rectangle("Прямоугольник", a, b) {}