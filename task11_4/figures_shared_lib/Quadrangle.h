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
    FIGURE_API_EXPORTS int get_side_a();
    FIGURE_API_EXPORTS int get_side_b();
    FIGURE_API_EXPORTS int get_side_c();
    FIGURE_API_EXPORTS int get_side_d();
    FIGURE_API_EXPORTS int get_angle_A();
    FIGURE_API_EXPORTS int get_angle_B();
    FIGURE_API_EXPORTS int get_angle_C();
    FIGURE_API_EXPORTS int get_angle_D();
    FIGURE_API_EXPORTS Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);

    FIGURE_API_EXPORTS std::string to_string() override;
};