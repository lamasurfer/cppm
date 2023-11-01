#pragma once
#include "Figure.h"

class Quadrangle : public Figure {
private:
    int a;
    int b;
    int c;
    int d;
    int A;
    int B;
    int C;
    int D;
protected:
    Quadrangle(std::string name, int a, int b, int c, int d, int A, int B, int C, int D);
public:
    int get_side_a();
    int get_side_b();
    int get_side_c();
    int get_side_d();
    int get_angle_A();
    int get_angle_B();
    int get_angle_C();
    int get_angle_D();
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);

    std::string to_string() override;
};