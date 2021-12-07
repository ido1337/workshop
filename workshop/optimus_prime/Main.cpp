#include <iostream>


/*
 * returns if a given number is prime
 * @param num a given number
 * @return true if num is prime else false
*/
bool is_prime_number(const unsigned long num) {
    for (int i = 2; i <= std::sqrt(num); i++) {
        if (num % i == 0) {
            return false; // number is not prime
        }
    }
    return true; // num is prime
}


int main() {
    unsigned long num = 0;

    std::cout << "Enter number to check if it is prime: ";
    std::cin >> num;
    std::cout << "Is it Prime? " << (is_prime_number(num) ? "Yes" : "No") << std::endl;
    
    return 0;
}