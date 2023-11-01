#pragma once
#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
protected:
    IsoscelesTriangle(std::string name, int a, int b, int A, int B);
public:
    FIGURE_API_EXPORTS IsoscelesTriangle(int a, int b, int A, int B);
};