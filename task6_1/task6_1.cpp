#include <iostream>
#include <regex>
#include "math_funcs.h"

int main() {

    setlocale(LC_ALL, "rus");

	int a = 0;
	std::cout << "Введите первое число: ";
	std::cin >> a;

	int b = 0;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	
	int operation = 0;
	std::cout << "Выберите операцию(1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень) : ";
	std::cin >> operation;

	switch (operation) {
	case 1:
		std::cout << a << " плюс " << b << " = " << add(a, b);
		break;
	case 2:
		std::cout << a << " минус " << b << " = " << substract(a, b);
		break;
	case 3:
		std::cout << a << " умножить на " << b << " = " << multiply(a, b);
		break;
	case 4:
		std::cout << a << " разделить на " << b << " = " << divide(a, b);
		break;
	case 5:
		std::cout << a << " в степени " << b << " = " << power(a, b);
		break;
	default:
		std::cout << "Нет такой операции";
		break;
	}

    return 0;
}