#include <iostream>
#include <sstream>

class Figure {
private:
    std::string name;
    int sides_count;
    int sides_sum;
    int angles_count;
    int angles_sum;
protected:
    Figure(std::string name, int sides_count, int sides_sum, int angles_count, int angles_sum) {
        this->name = name;
        this->sides_count = sides_count;
        this->sides_sum = sides_sum;
        this->angles_count = angles_count;
        this->angles_sum = angles_sum;
    }
public:
    Figure() : Figure("Фигура", 0, 0, 0, 0) {}
    std::string get_name() { return name; }
    int get_sides_count() { return sides_count; }
    int get_sides_sum() { return sides_sum; }
    int get_angles_count() { return angles_count; }
    int get_angles_sum() { return angles_sum; }

    virtual std::string to_string() {
        std::stringstream ss;
        ss << name << ": " << sides_count << '\n';
        return ss.str();
    }

    virtual bool check() {
        return sides_count == 0;
    }

    virtual void print_info() {
        std::cout << name << ":\n";
        std::cout << (check() == true ? "Правильная" : "Неправильная") << '\n';
        std::cout << "Количество сторон: " << sides_count << '\n';
    }
};

class Triangle : public Figure {
private:
    int a;
    int b;
    int c;
    int A;
    int B;
    int C;
protected:
    Triangle(std::string name, int a, int b, int c, int A, int B, int C) : Figure(name, 3, a + b + c, 3, A + B + C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
public:
    int get_side_a() { return a; }
    int get_side_b() { return b; }
    int get_side_c() { return c; }
    int get_angle_A() { return A; }
    int get_angle_B() { return B; }
    int get_angle_C() { return C; }
    Triangle(int a, int b, int c, int A, int B, int C) : Triangle("Треугольник", a, b, c, A, B, C) {}

    std::string to_string() override {
        std::stringstream ss;
        ss << Figure::get_name() << ":\n";
        ss << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n';
        ss << "Углы: A=" << A << " B=" << B << " C=" << C << '\n';
        return ss.str();
    }

    bool check() override {
        return Figure::get_sides_count() == 3 && (A + B + C) == 180;
    }

    void print_info() override {
        std::cout << '\n';
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n';
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << '\n';
    }
};

class RectangularTriangle : public Triangle {
public:
    RectangularTriangle(int a, int b, int c, int A, int B) : Triangle("Прямоугольный треугольник", a, b, c, A, B, 90) {}

    bool check() override {
        return Triangle::check() && Triangle::get_angle_C() == 90;
    }
};

class IsoscelesTriangle : public Triangle {
protected:
    IsoscelesTriangle(std::string name, int a, int b, int A, int B) : Triangle(name, a, b, a, A, B, A) {}
public:
    IsoscelesTriangle(int a, int b, int A, int B) : IsoscelesTriangle("Равнобедренный треугольник", a, b, A, B) {}

    bool check() override {
        return Triangle::check() &&
            Triangle::get_side_a() == Triangle::get_side_c() &&
            Triangle::get_angle_A() == Triangle::get_angle_C();
    }
};

class EquilateralTriangle : public IsoscelesTriangle {
public:
    EquilateralTriangle(int a) : IsoscelesTriangle("Равносторонний треугольник", a, a, 60, 60) {}

    bool check() override {
        return IsoscelesTriangle::check() &&
            Triangle::get_side_a() == Triangle::get_side_b() && Triangle::get_side_b() == Triangle::get_side_c() &&
            Triangle::get_angle_A() == 60 && Triangle::get_angle_B() == 60 && Triangle::get_angle_C() == 60;
    }
};

class Quadrangle : public Figure {
private:
    int a;
    int b;
    int c;
    int d;
    int A;
    int B;
    int C;
    int D;
protected:
    Quadrangle(std::string name, int a, int b, int c, int d, int A, int B, int C, int D) : Figure(name, 4, a + b + c + d, 4, A + B + C + D) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
public:
    int get_side_a() { return a; }
    int get_side_b() { return b; }
    int get_side_c() { return c; }
    int get_side_d() { return d; }
    int get_angle_A() { return A; }
    int get_angle_B() { return B; }
    int get_angle_C() { return C; }
    int get_angle_D() { return D; }
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle("Четырехуголник", a, b, c, d, A, B, C, D) {}

    std::string to_string() override {
        std::stringstream ss;
        ss << Figure::get_name() << ":\n";
        ss << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n';
        ss << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << '\n';
        return ss.str();
    }

    bool check() override {
        return Figure::get_sides_count() == 4 && (A + B + C + D) == 360;
    }

    void print_info() override {
        std::cout << '\n';
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n';
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << '\n';
    }
};

class Parallelogram : public Quadrangle {
protected:
    Parallelogram(std::string name, int a, int b, int A, int B) : Quadrangle(name, a, b, a, b, A, B, A, B) {}
public:
    Parallelogram(int a, int b, int A, int B) : Parallelogram("Параллелограмм", a, b, A, B) {}

    bool check() override {
        return Quadrangle::check() &&
            Quadrangle::get_side_a() == Quadrangle::get_side_c() && Quadrangle::get_side_b() == Quadrangle::get_side_d() &&
            Quadrangle::get_angle_A() == Quadrangle::get_angle_C() && Quadrangle::get_angle_B() == Quadrangle::get_angle_D();
    }
};

class Rectangle : public Parallelogram {
protected:
    Rectangle(std::string name, int a, int b) : Parallelogram(name, a, b, 90, 90) {}
public:
    Rectangle(int a, int b) : Rectangle("Прямоугольник", a, b) {}

    bool check() override {
        return Parallelogram::check() &&
            Quadrangle::get_angle_A() == 90 && Quadrangle::get_angle_B() == 90 && Quadrangle::get_angle_C() == 90 && Quadrangle::get_angle_D() == 90;
    }
};

class Rhombus : public Parallelogram {
protected:
    Rhombus(std::string name, int a, int A, int B) : Parallelogram(name, a, a, A, B) {}
public:
    Rhombus(int a, int A, int B) : Rhombus("Ромб", a, A, B) {}

    bool check() override {
        return Parallelogram::check() &&
            Quadrangle::get_side_a() == Quadrangle::get_side_b() && Quadrangle::get_side_b() == Quadrangle::get_side_c() && Quadrangle::get_side_c() == Quadrangle::get_side_d();
    }
};

class Square : public Rhombus {
public:
    Square(int a) : Rhombus("Квадрат", a, 90, 90) {}

    bool check() override {
        return Rhombus::check() &&
            Quadrangle::get_angle_A() == 90 && Quadrangle::get_angle_B() == 90 && Quadrangle::get_angle_C() == 90 && Quadrangle::get_angle_D() == 90;
    }
};

int main() {

    setlocale(LC_ALL, "rus");

    Figure figure;
    figure.print_info();

    Triangle triangle(10, 20, 30, 50, 60, 70);
    triangle.print_info();

    RectangularTriangle rectangularTriangle(10, 20, 30, 50, 60);
    rectangularTriangle.print_info();

    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    isoscelesTriangle.print_info();

    EquilateralTriangle equilateralTriangle(30);
    equilateralTriangle.print_info();

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    quadrangle.print_info();

    Rectangle rectangle(10, 20);
    rectangle.print_info();

    Square square(20);
    square.print_info();

    Parallelogram parallelogram(20, 30, 30, 40);
    parallelogram.print_info();

    Rhombus rhombus(30, 30, 40);
    rhombus.print_info();

    return 0;
}