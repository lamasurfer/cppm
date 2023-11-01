#include "Parallelogram.h"

Parallelogram::Parallelogram(std::string name, int a, int b, int A, int B) : Quadrangle(name, a, b, a, b, A, B, A, B) {}
Parallelogram::Parallelogram(int a, int b, int A, int B) : Parallelogram("ֿאנאככוכמדנאלל", a, b, A, B) {}