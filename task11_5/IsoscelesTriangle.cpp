#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(std::string name, int a, int b, int A, int B) : Triangle(name, a, b, a, A, B, A) {}
IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B) : IsoscelesTriangle("Равнобедренный треугольник", a, b, A, B) {}