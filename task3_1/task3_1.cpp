#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

class Calculator {
private:
	double num1;
	double num2;
public:
	double add() { return num1 + num2; }
	double multiply() { return num1 * num2; }
	double subtract_1_2() { return num1 - num2; }
	double subtract_2_1() { return num2 - num1; }
	double divide_1_2() { return num1 / num2; }
	double divide_2_1() { return num2 / num1; }
	bool set_num1(double num1) {
		if (num1 == 0.0) {
			return false;
		}
		this->num1 = num1;
		return true;
	}
	bool set_num2(double num2) {
		if (num2 == 0.0) {
			return false;
		}
		this->num2 = num2;
		return true;
	}
};

double processDoubleInput();


int main() {

	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "us"); // для double формата 5.5

	double num1 = 0;
	double num2 = 0;

	std::string input = "";
	while (true) {
		std::cout << "Введите num1: ";
		num1 = processDoubleInput();

		std::cout << "Введите num2: ";
		num2 = processDoubleInput();

		Calculator calc;

		bool set1 = calc.set_num1(num1);
		bool set2 = calc.set_num2(num2);

		if (set1 && set2) {
			std::cout << std::fixed << std::setprecision(2)
				<< "num1 + num2 = " << std::setprecision(2) << calc.add() << '\n'
				<< "num1 - num2 = " << calc.subtract_1_2() << '\n'
				<< "num2 - num1 = " << calc.subtract_2_1() << '\n'
				<< "num1 * num2 = " << calc.multiply() << '\n'
				<< "num1 / num2 = " << calc.divide_1_2() << '\n'
				<< "num2 / num1 = " << calc.divide_2_1() << '\n';
		}
		else {
			std::cout << "Произошла ошибка!\n";
		}
	}
	return 0;
}

double processDoubleInput() {
	std::string input;
	std::regex regex("(-{0,1}\\d+)|(-{0,1}\\d+\\.*\\d+)");
	std::smatch match;
	double result = 0;
	while (std::getline(std::cin, input)) {
		if (std::regex_match(input, match, regex)) {
			try {
				result = std::stod(input);
				if (result == 0) {
					std::cout << "Введите число, не равное 0\n";
					continue;
				}
				break;
			}
			catch (std::out_of_range const& e) {
				std::cout << "Вы ввели слишком большое число\n";
			}
		}
		else {
			std::cout << "Введите число, например 1000, или -50.5\n";
		}
	}
	return result;
}