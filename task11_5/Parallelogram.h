#pragma once
#include "Quadrangle.h"

class Parallelogram : public Quadrangle {
protected:
    Parallelogram(std::string name, int a, int b, int A, int B);
public:
    FIGURE_API_EXPORTS Parallelogram(int a, int b, int A, int B);
};