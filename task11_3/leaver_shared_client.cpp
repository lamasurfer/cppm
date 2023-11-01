#include <iostream>
#include <string>
#include "leaver.h"

int main() {

    setlocale(LC_ALL, "rus");

    std::string name = "";
    std::cout << "Введите имя: ";
    std::cin >> name;

    Leaver leaver;
    std::string leaving = leaver.leave(name);

    std::cout << leaving << '\n';

    return 0;
}