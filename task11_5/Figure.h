#pragma once
#include <string>

#ifdef FIGURE_API_EXPORTS
#define FIGURE_API_EXPORTS __declspec(dllexport)
#else
#define FIGURE_API_EXPORTS __declspec(dllimport)
#endif

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
    FIGURE_API_EXPORTS Figure();
    FIGURE_API_EXPORTS std::string get_name();
    FIGURE_API_EXPORTS int get_sides_count();
    FIGURE_API_EXPORTS int get_sides_sum();
    FIGURE_API_EXPORTS int get_angles_count();
    FIGURE_API_EXPORTS int get_angles_sum();

    FIGURE_API_EXPORTS virtual std::string to_string();
};