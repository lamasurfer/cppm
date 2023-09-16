#include <iostream>
#include <Windows.h>
#include <string>

struct Address {

    std::string cityName;
    std::string streetName;
    unsigned int houseNumber;
    unsigned int flatNumber;
    unsigned int postCode;

};

void printAddress(Address& address);

int main() {

    setlocale(LC_ALL, "rus");

    Address address1 = { "Москва", "Арбат", 12, 8, 123456 };
    Address address2 = { "Ижевск", "Пушкина", 59, 143, 953769 };

    printAddress(address1);
    std::cout << '\n';
    printAddress(address2);

    return 0;
}

void printAddress(Address& address) {
    std::cout << "Город: " << address.cityName << '\n'
        << "Улица: " << address.streetName << '\n'
        << "Номер дома: " << address.houseNumber << '\n'
        << "Номер квартиры: " << address.flatNumber << '\n'
        << "Индекс: " << address.postCode << '\n';
}