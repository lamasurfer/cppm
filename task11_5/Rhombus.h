#pragma once
#include "Parallelogram.h"

class Rhombus : public Parallelogram {
protected:
    Rhombus(std::string name, int a, int A, int B);
public:
    FIGURE_API_EXPORTS Rhombus(int a, int A, int B);
};