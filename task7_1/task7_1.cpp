#include <iostream>

#define MODE 1
#ifndef MODE
#error MODE constant undefined
#elif MODE == 1
int add(int a, int b) { return a + b; }
#endif

int main() {

    setlocale(LC_ALL, "rus");

#if MODE == 0
    std::cout << "Работаю в режиме тренировки\n";
#elif MODE == 1
    std::cout << "Работаю в боевом режиме\n";
    int a = 0;
    std::cout << "Введите число 1: ";
    std::cin >> a;
    int b = 0;
    std::cout << "Введите число 2: ";
    std::cin >> b;
    std::cout << "Результат сложения: " << add(a, b) << '\n';
#else
    std::cout << "Неизвестный режим. Завершение работы\n";
#endif

    return 0;
}