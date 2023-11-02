#include <iostream>

class Fraction {
private:
    int numerator_;
    int denominator_;
private:
    static int common_divisor(int denominator_1, int denominator_2) {
        int result = 0;
        for (int i = 1; i <= denominator_1 && i <= denominator_2; i++) {
            if (denominator_1 % i == 0 && denominator_2 % i == 0)
                result = i;
        }
        return result;
    }

public:
    Fraction(int numerator, int denominator) {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    Fraction operator+(const Fraction &right) {
        int numerator = numerator_ * right.denominator_ + right.numerator_ * denominator_;
        int denominator = denominator_ * right.denominator_;

        int common = abs(common_divisor(numerator, denominator));
        if (common > 1) {
            numerator = numerator / common;
            denominator = denominator / common;
        }
        return Fraction(numerator, denominator);
    }

    Fraction operator-(const Fraction &right) {
        int numerator = numerator_ * right.denominator_ - right.numerator_ * denominator_;
        int denominator = denominator_ * right.denominator_;

        int common = abs(common_divisor(numerator, denominator));
        if (common > 1) {
            numerator = numerator / common;
            denominator = denominator / common;
        }
        return Fraction(numerator, denominator);
    }

    Fraction operator*(const Fraction &right) {

        int numerator = numerator_ * right.numerator_;
        int denominator = denominator_ * right.denominator_;

        int common = abs(common_divisor(numerator, denominator));
        if (common > 1) {
            numerator = numerator / common;
            denominator = denominator / common;
        }
        return Fraction(numerator, denominator);
    }

    Fraction operator/(const Fraction &right) {

        int numerator = numerator_ * right.denominator_;
        int denominator = denominator_ * right.numerator_;

        int common = abs(common_divisor(numerator, denominator));
        if (common > 1) {
            numerator = numerator / common;
            denominator = denominator / common;
        }
        return Fraction(numerator, denominator);
    }

    Fraction &operator-() {
        numerator_ = -(numerator_);
        return *this;
    }

    Fraction &operator++() {
        numerator_ += denominator_;
        return *this;
    }

    Fraction operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction &operator--() {
        numerator_ -= denominator_;
        return *this;
    }

    Fraction operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    friend std::ostream &operator<<(std::ostream &ostream, const Fraction &fraction);
};

std::ostream &operator<<(std::ostream &ostream, const Fraction &fraction) {
    return ostream << fraction.numerator_ << '/' << fraction.denominator_;
}

int main() {

    setlocale(LC_ALL, "rus");

    int numerator1 = 0;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> numerator1;
    int denominator1 = 0;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> denominator1;
    int numerator2 = 0;
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> numerator2;
    int denominator2 = 0;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> denominator2;

    Fraction f1(numerator1, denominator1);
    Fraction f2(numerator2, denominator2);

    std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << '\n';
    std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << '\n';
    std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << '\n';
    std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << '\n';

    std::cout << "++" << f1 << " * " << f2 << " = " << (++f1 * f2) << '\n';
    std::cout << "Значение дроби 1 = " << f1 << '\n';
    std::cout << f1 << "--" << " * " << f2 << " = " << (f1-- * f2) << '\n';
    std::cout << "Значение дроби 1 = " << f1 << '\n';

    return 0;
}
