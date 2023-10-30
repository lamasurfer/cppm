#include <iostream>
#include <string>

class Figure {
private:
    std::string name;
    int sides_count;
protected:
    Figure(std::string name, int sides_count) {
        this->name = name;
        this->sides_count = sides_count;
    }
public:
    Figure() : Figure("Фигура", 0) {}
    std::string get_name() { return name; }
    int get_sides_count() { return sides_count; }
};

class Triangle : public Figure {
public:
    Triangle() : Figure("Треугольник", 3) {}
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure("Прямоугольник", 4) {}

};

int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "Количество сторон:\n";

    Figure figure;
    std::cout << figure.get_name() << ": " << figure.get_sides_count() << '\n';

    Triangle triangle;
    std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << '\n';

    Quadrangle quadrangle;
    std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << '\n';

    return 0;
}