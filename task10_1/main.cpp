﻿#include <iostream>
#include <string>

int main() {

    setlocale(LC_ALL, "rus");

    std::string name = "";
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "Здравствуйте, " << name << "!\n";

    return 0;
}