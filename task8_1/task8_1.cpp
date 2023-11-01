#include <iostream>
#include <string>

class BadLengthException : public std::exception {
public:
    const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }
};

int function(std::string str, int forbidden_length);

int main() {

    setlocale(LC_ALL, "rus");

    int forbidden_length = 0;
    std::string str = "";
    int length = 0;
    
    while (true) {
        std::cout << "Введите запретную длину: ";
        std::cin >> forbidden_length;

        std::cout << "Введите слово: ";
        std::cin >> str;

        try {
            length = function(str, forbidden_length);
            std::cout << "Длина слова \"" + str + "\" равна " << length << '\n';
        }
        catch (const BadLengthException& e) {
            std::cout << e.what() << '\n';
            break;
        }
    }
  
    return 0;
}

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw BadLengthException();
    }
    return str.length();
}