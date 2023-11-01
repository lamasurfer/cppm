#pragma once
#include "Parallelogram.h"

class Rectangle : public Parallelogram {
protected:
    Rectangle(std::string name, int a, int b);
public:
    Rectangle(int a, int b);
};