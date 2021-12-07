#include <iostream>

int main() {
    unsigned long num = 0;

    std::cout << "Please enter a number to calculate its square root!" << std::endl;
    std::cin >> num;
    std::cout << "The number square root is: " << std::sqrt(num) << std::endl;

    return 0;
}