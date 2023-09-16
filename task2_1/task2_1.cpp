#include <iostream>
#include <string>

enum class Months {
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

std::string getMonthString(Months month);

int main() {

	setlocale(LC_ALL, "rus");

	int input = 0;

	do {
		std::cout << "Введите номер месяца или 0 для выхода: ";
		std::cin >> input;
		if (input >= 1 && input <= 12) {
			Months month = static_cast<Months>(input);
			std::string monthString = getMonthString(month);
			std::cout << monthString << '\n';
		}
		else if (input != 0) {
			std::cout << "Неправильный номер!\n";
		}
	} while (input != 0);

	std::cout << "До свидания!\n";

	return 0;
}

std::string getMonthString(Months month) {
	switch (month) {
	case Months::JANUARY:
		return "Январь";
	case Months::FEBRUARY:
		return "Февраль";
	case Months::MARCH:
		return "Март";
	case Months::APRIL:
		return "Апрель";
	case Months::MAY:
		return "Май";
	case Months::JUNE:
		return "Июнь";
	case Months::JULY:
		return "Июль";
	case Months::AUGUST:
		return "Август";
	case Months::SEPTEMBER:
		return "Сентябрь";
	case Months::OCTOBER:
		return "Октябрь";
	case Months::NOVEMBER:
		return "Ноябрь";
	case Months::DECEMBER:
		return "Декабрь";
	default:
		return "Неизвесмтный месяц";
	}
}