#include "Rhombus.h"

Rhombus::Rhombus(std::string name, int a, int A, int B) : Parallelogram(name, a, a, A, B) {}
Rhombus::Rhombus(int a, int A, int B) : Rhombus("����", a, A, B) {}