#include <iostream>
#include <string>
#include <regex>
#include "Counter.h"

int processIntInput();

int main() {
    setlocale(LC_ALL, "rus");

    std::string input = "";
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";

    Counter counter;

    std::getline(std::cin, input);
    if (input == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        int value = processIntInput();
        counter.set_value(value);
    }

    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::getline(std::cin, input);
        if (input == "+") {
            counter.increment();
        }
        else if (input == "-") {
            counter.decrement();
        }
        else if (input == "=") {
            std::cout << counter.get_value() << '\n';
        }
    } while (input != "x");

    std::cout << "До свидания!\n";

    return 0;
}

int processIntInput() {
    std::string input;
    std::regex longRegex("\\d+");
    std::smatch match;
    int result = 0;
    while (std::getline(std::cin, input)) {
        if (std::regex_match(input, match, longRegex)) {
            try {
                result = std::stoi(input);
                break;
            }
            catch (std::out_of_range const& e) {
                std::cout << "Вы ввели слишком большое число\n";
            }
        }
        else {
            std::cout << "Введите число, например 1000\n";
        }
    }
    return result;
}