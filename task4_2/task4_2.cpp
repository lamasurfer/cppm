#include <iostream>
#include <fstream>
#include <sstream>

class Address {
private:
    std::string city{};
    std::string street{};
    int house{};
    int flat{};
public:
    Address() {}
    Address(std::string city, std::string street, int house, int flat) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->flat = flat;
    }
    std::string get_city() { return city; }
    void set_city(std::string city) { this->city = city; }
    std::string get_street() { return street; }
    void set_street(std::string street) { this->street = street; }
    int get_house() { return house; }
    void set_house(int house) { this->house = house; }
    int get_flat() { return flat; }
    void set_flat(int flat) { this->flat = flat; }

    std::string get_output_address() {
        std::stringstream ss;
        ss << city << ", " << street << ", " << house << ", " << flat;
        return ss.str();
    }
};

void sort(Address* addresses, const int size);
void quick_sort(Address* addresses, int first, int last);

int main() {
    setlocale(LC_ALL, "rus");

    std::ifstream ifs("in.txt");

    if (!ifs.is_open()) {
        std::cout << "Ошибка при открытии файла!";
        return 1;
    }

    int input = 0;
    ifs >> input;
    const int SIZE = input;

    Address* addresses = new Address[SIZE]();
    for (int i = 0; i < SIZE; i++) {
        std::string city{};
        std::string street{};
        int house{};
        int flat{};
        ifs >> city >> street >> house >> flat;
        Address& address = addresses[i];
        address.set_city(city);
        address.set_street(street);
        address.set_house(house);
        address.set_flat(flat);
    }

    ifs.close();

    std::ofstream ofs("out.txt");
    if (!ofs.is_open()) {
        std::cout << "Ошибка при записи файла!";
        return 1;
    }

    sort(addresses, SIZE);

    for (int i = 0; i < SIZE; i++) {
        ofs << addresses[i].get_output_address() << '\n';
    }

    ofs.close();

    delete[] addresses;

    return 0;

}

void sort(Address* addresses, const int size) {
    quick_sort(addresses, 0, size - 1);
}

void quick_sort(Address* addresses, int first, int last) {
    int i = first;
    int j = last;
    int middle = (first + last) / 2;

    std::string a = addresses[middle].get_city();
    do {
        while ((addresses[i].get_city() < a) && (i < last)) {
            i++;
        }
        while ((a < addresses[j].get_city()) && (j > first)) {
            j--;
        }
        if (i <= j) {

            Address temp = addresses[i];
            addresses[i] = addresses[j];
            addresses[j] = temp;

            i++;
            j--;
        }

    } while (i <= j);

    if (first < j) {
        quick_sort(addresses, first, j);
    }
    if (i < last) {
        quick_sort(addresses, i, last);
    }
}