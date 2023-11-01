#pragma once
#include "Parallelogram.h"

class Rectangle : public Parallelogram {
protected:
    Rectangle(std::string name, int a, int b);
public:
    FIGURE_API_EXPORTS Rectangle(int a, int b);
};