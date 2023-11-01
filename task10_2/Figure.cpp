#include "Figure.h"
#include <sstream>
#include <string>

Figure::Figure(std::string name, int sides_count, int sides_sum, int angles_count, int angles_sum) {
    this->name = name;
    this->sides_count = sides_count;
    this->sides_sum = sides_sum;
    this->angles_count = angles_count;
    this->angles_sum = angles_sum;
}
Figure::Figure() : Figure("Фигура", 0, 0, 0, 0) {}
std::string Figure::get_name() { return name; }
int Figure::get_sides_count() { return sides_count; }
int Figure::get_sides_sum() { return sides_sum; }
int Figure::get_angles_count() { return angles_count; }
int Figure::get_angles_sum() { return angles_sum; }

std::string Figure::to_string() {
    std::stringstream ss;
    ss << name << ": " << sides_count << '\n';
    return ss.str();
}