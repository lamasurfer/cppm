#pragma once
#include "Parallelogram.h"

class Rhombus : public Parallelogram {
protected:
    Rhombus(std::string name, int a, int A, int B);
public:
    Rhombus(int a, int A, int B);
};