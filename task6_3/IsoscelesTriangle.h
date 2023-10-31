#pragma once
#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
protected:
    IsoscelesTriangle(std::string name, int a, int b, int A, int B);
public:
    IsoscelesTriangle(int a, int b, int A, int B);
};