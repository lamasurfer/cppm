#include <iostream>
#include <string>
#include "greeter.h"

int main() {

    setlocale(LC_ALL, "rus");

    std::string name = "";
    std::cout << "Введите имя: ";
    std::cin >> name;

    Greeter greeter;
    std::string greeting = greeter.greet(name);

    std::cout << greeting << '\n';

    return 0;
}