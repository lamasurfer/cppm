#pragma once
#include "Figure.h"

class Triangle : public Figure {
private:
    int a;
    int b;
    int c;
    int A;
    int B;
    int C;
protected:
    Triangle(std::string name, int a, int b, int c, int A, int B, int C);
public:
    int get_side_a();
    int get_side_b();
    int get_side_c();
    int get_angle_A();
    int get_angle_B();
    int get_angle_C();
    Triangle(int a, int b, int c, int A, int B, int C);

    std::string to_string() override;
};