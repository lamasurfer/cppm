#pragma once
#include <string>
#include "FigureParamsException.h"

class Figure {
private:
    std::string name;
    int sides_count;
    int sides_sum;
    int angles_count;
    int angles_sum;
protected:
    Figure(std::string name, int sides_count, int sides_sum, int angles_count, int angles_sum);
public:
    Figure();
    std::string get_name();
    int get_sides_count();
    int get_sides_sum();
    int get_angles_count();
    int get_angles_sum();

    virtual std::string to_string();
};