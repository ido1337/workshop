#include <iostream>
#include "ComplexNumber.h"

int main() {
    ComplexNumber a;
    ComplexNumber b(0, 2);
    ComplexNumber c(2, 0);
    ComplexNumber d(-2, -2);
    ComplexNumber e(2, 2);

    std::cout << "Here is number a: " << a << std::endl;
    std::cout << "Here is number b: " << b << std::endl;
    std::cout << "Here is number c: " << c << std::endl;
    std::cout << "Here is number d: " << d << std::endl;
    std::cout << "Here is number e: " << e << std::endl;

    std::cout << a << " + " << e << " = " << a + e << std::endl;
    std::cout << a << " - " << e << " = " << a - e << std::endl;
    std::cout << a << " * " << e << " = " << a * e << std::endl;

    std::cout << c << " + " << e << " = " << c + e << std::endl;
    std::cout << d << " * " << d << " = " << d * d << std::endl;
    std::cout << e << " - " << c << " = " << e - c << std::endl;
}