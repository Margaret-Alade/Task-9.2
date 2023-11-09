//
//  main.cpp
//  Task-9.2
//
//  Created by Маргарет  on 08.11.2023.
//

#include <iostream>

unsigned int greatest_common_divisor(unsigned int a, unsigned int b) {
  if (a % b == 0)
    return b;
  if (b % a == 0)
    return a;
  if (a > b)
      return greatest_common_divisor(a%b, b);
    return greatest_common_divisor(a, b%a);
}

unsigned int least_common_multiple(unsigned int a, unsigned int b) {
  return (a*b)/greatest_common_divisor(a,b);
}

class Fraction
{
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator) {
        numerator_ = numerator;
        denominator_ = denominator;
    }
    
    Fraction operator+(Fraction right) {
        unsigned int result_denominator = least_common_multiple(denominator_, right.denominator_);
        unsigned int result_numerator = (numerator_ * (result_denominator / denominator_)) + (right.numerator_ * (result_denominator / right.denominator_));
        return Fraction(result_numerator, result_denominator);
    }
    
    Fraction operator-(Fraction right) {
        int result_denominator = least_common_multiple(denominator_, right.denominator_);
        int result_numerator = (numerator_ * (result_denominator / denominator_)) - (right.numerator_ * (result_denominator / right.denominator_));
        return Fraction(result_numerator, result_denominator);
    }
    
    Fraction operator*(Fraction right) {
        int result_denominator = (denominator_ * right.denominator_);
        int result_numerator = numerator_ * right.numerator_;
        int result_denominator_ = result_denominator / greatest_common_divisor(result_denominator, result_numerator);
        int result_numerator_ = result_numerator / greatest_common_divisor(result_denominator, result_numerator);
        return Fraction(result_numerator_, result_denominator_);
    }
    
    Fraction operator/(Fraction right) {
        int result_denominator = (denominator_ * right.numerator_);
        int result_numerator = numerator_ * right.denominator_;
        int result_denominator_ = result_denominator / greatest_common_divisor(result_denominator, result_numerator);
        int result_numerator_ = result_numerator / greatest_common_divisor(result_denominator, result_numerator);
        return Fraction(result_numerator_, result_denominator_);
    }
    
    Fraction operator-() {
        return Fraction(numerator_ * -1, denominator_);
    }
    
    Fraction operator++(){
        numerator_ = numerator_ + denominator_;
        return *this;
    }
    
    Fraction operator++(int) {
        Fraction temp = *this;
        numerator_ = numerator_ + denominator_;
        return temp;
    }
    
    Fraction operator--(){
        numerator_ = numerator_ - denominator_;
        return *this;
    }
    
    Fraction operator--(int) {
        Fraction temp = *this;
        numerator_ = numerator_ + denominator_;
        return temp;
    }
    std::string print_f() {
        return std::to_string(numerator_) + "/" + std::to_string(denominator_);
    }
    
};

int main()
{
    
    int num_1, denom_1, num_2, denom_2;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> num_1;
    std::cout << '\n';
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> denom_1;
    std::cout << '\n';
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> num_2;
    std::cout << '\n';
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> denom_2;
    std::cout << '\n';
    Fraction f1(num_1,denom_1);
    Fraction f2(num_2,denom_2);
    Fraction f3 = f1 + f2;
    std::cout << f1.print_f() << " + " << f2.print_f() << " = " << f3.print_f() << '\n';
    f3 = f1 - f2;
    std::cout << f1.print_f() << " - " << f2.print_f() << " = " << f3.print_f() << '\n';
    f3 = f1 * f2;
    std::cout << f1.print_f() << " * " << f2.print_f() << " = " << f3.print_f() << '\n';
    f3 = f1 / f2;
    std::cout << f1.print_f() << " / " << f2.print_f() << " = " << f3.print_f() << '\n';
    Fraction f5 = f1;
    f3 = (++f1) * f2;
    std::cout << "++" << f5.print_f() << " * " << f2.print_f() << " = " << f3.print_f() << '\n';
    std::cout << "Значение дроби 1 = 7/4" << '\n';
    Fraction f4(7,4);
    f5 = f4;
    f3 = (f4--) * f2;
    std::cout << f5.print_f() << "-- * " << f2.print_f() << " = " << f3.print_f() << '\n';
    f3 = -f2;
    std::cout << f3.print_f() << '\n';
    
    
    
    
    
    
    
    
    return 0;
}
