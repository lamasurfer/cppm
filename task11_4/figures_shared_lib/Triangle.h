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
    FIGURE_API_EXPORTS int get_side_a();
    FIGURE_API_EXPORTS int get_side_b();
    FIGURE_API_EXPORTS int get_side_c();
    FIGURE_API_EXPORTS int get_angle_A();
    FIGURE_API_EXPORTS int get_angle_B();
    FIGURE_API_EXPORTS int get_angle_C();
    FIGURE_API_EXPORTS Triangle(int a, int b, int c, int A, int B, int C);

    FIGURE_API_EXPORTS std::string to_string() override;
};