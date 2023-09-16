#include <iostream>
#include <string>
#include <regex>

struct Account {
	int number;
	std::string name;
	double amount;
};

int processIntInput();
double processDoubleInput();
void changeAccountAmount(Account* account, double amount);

int main() {
	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "en"); // для double формата 5.5

	std::string input = "";

	std::cout << "Введите номер счета: ";
	long accountNumber = processIntInput();

	std::string ownerName = "";
	std::cout << "Введите имя владельца: ";
	std::getline(std::cin, ownerName);

	std::cout << "Введите баланс: ";
	double accountAmount = processDoubleInput();

	Account account = { accountNumber, ownerName, accountAmount };


	std::cout << "Введите новый баланс: ";
	double newAmount = processDoubleInput();

	changeAccountAmount(&account, newAmount);

	std::cout << "Ваш счет: " << account.name << ", "
		<< account.number << ", "
		<< account.amount << '\n';

	return 0;
}

// попробовал немного забежать вперед и сделать пользовательский ввод более надежным
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

double processDoubleInput() {
	std::string input;
	std::regex longRegex("(\\d+)|(\\d+\\.\\d+)");
	std::smatch match;
	double result = 0;
	while (std::getline(std::cin, input)) {
		if (std::regex_match(input, match, longRegex)) {
			try {
				result = std::stod(input);
				break;
			}
			catch (std::out_of_range const& e) {
				std::cout << "Вы ввели слишком большое число\n";
			}
		}
		else {
			std::cout << "Введите число, например 1000 1000, или 50.5\n";
		}
	}
	return result;
}

void changeAccountAmount(Account* account, double amount) {
	account->amount = amount;
}