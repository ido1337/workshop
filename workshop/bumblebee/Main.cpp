#include <iostream>
#include <vector>

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


/*
 * receive from stdin amount of first prime numbers to print
 * @return amount of first prime numbers to print
*/
const unsigned long get_amount_of_first_prime_numbers() {
    unsigned long primes_amount = 0;

    std::cout << "Enter amount of prime numbers to receive: ";
    std::cin >> primes_amount;

    return primes_amount;
}


/*
 * calculating the first n prime numbers and return them in a vector
 * @param primes_amount amount of first prime numbers to find
 * @return the n first prime numbers in vector
*/
std::vector<unsigned long> get_first_n_prime_numbers(const unsigned long primes_amount) {
    std::vector<unsigned long> primes(primes_amount);

    unsigned long last_prime = 2;
    for (int i = 0; i < primes_amount; i++) {
        while (!is_prime_number(last_prime)) {
            last_prime++;
        }

        primes[i] = last_prime;
        last_prime++;
    }
    return std::move(primes);
}


int main() {
    unsigned long primes_amount = get_amount_of_first_prime_numbers();
    std::vector<unsigned long> primes = get_first_n_prime_numbers(primes_amount);

    std::cout << "Printing the first " << primes_amount << " prime numbers:" << std::endl;
    for (int i = 0; i < primes_amount; i++) {
        std::cout << primes[i] << std::endl;
    }

    return 0;
}