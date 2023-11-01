#pragma once
#include <stdexcept>

class FigureParamsException : public std::domain_error {
public:
    FigureParamsException(std::string message);
};