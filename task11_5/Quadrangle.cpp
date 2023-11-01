#include "Quadrangle.h"
#include <sstream>

Quadrangle::Quadrangle(std::string name, int a, int b, int c, int d, int A, int B, int C, int D) : Figure(name, 4, a + b + c + d, 4, A + B + C + D) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
}
int Quadrangle::get_side_a() { return a; }
int Quadrangle::get_side_b() { return b; }
int Quadrangle::get_side_c() { return c; }
int Quadrangle::get_side_d() { return d; }
int Quadrangle::get_angle_A() { return A; }
int Quadrangle::get_angle_B() { return B; }
int Quadrangle::get_angle_C() { return C; }
int Quadrangle::get_angle_D() { return D; }
Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle("Четырехуголник", a, b, c, d, A, B, C, D) {}

std::string Quadrangle::to_string() {
    std::stringstream ss;
    ss << Figure::get_name() << ":\n";
    ss << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n';
    ss << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << '\n';
    return ss.str();
}