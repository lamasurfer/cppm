#include "Triangle.h"
#include <sstream>

Triangle::Triangle(std::string name, int a, int b, int c, int A, int B, int C) : Figure(name, 3, a + b + c, 3, A + B + C) {
    if ((A + B + C) != 180) {
        throw FigureParamsException("Сумма углов должна быть равна 180");
    }
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
}
int Triangle::get_side_a() { return a; }
int Triangle::get_side_b() { return b; }
int Triangle::get_side_c() { return c; }
int Triangle::get_angle_A() { return A; }
int Triangle::get_angle_B() { return B; }
int Triangle::get_angle_C() { return C; }
Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Triangle("Треугольник", a, b, c, A, B, C) {}

std::string Triangle::to_string() {
    std::stringstream ss;
    ss << Figure::get_name() << ": ";
    ss << "(стороны: a=" << a << " b=" << b << " c=" << c << ';';
    ss << " углы: A=" << A << " B=" << B << " C=" << C << ')';
    return ss.str();
}