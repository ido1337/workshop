#include "Calculator.h"

/*
 * sum two numbers togther
 * @param a number to be added
 * @param b number to be added
 * @return a + b, sum of a and b
*/
double Calculator::add(double a, double b) noexcept {
    return a + b;
}


/*
 * substract two numbers
 * @param a number to substract from
 * @param b number to be substracted
 * @return a - b, a substracted by b
*/
double Calculator::substract(double a, double b) noexcept {
    return a - b;
}


/*
 * multiply two numbers
 * @param a number to be multiplied
 * @param b number to be multiplied
 * @return a * b, a mulyipled by b
*/
double Calculator::multiply(double a, double b) noexcept {
    return a * b;
}


/*
 * divide two numbers
 * @param a number to divide
 * @param b number to be divider
 * @return a / b, a divided by b
*/
double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}


/*
 * calculate the result of an operation between a and b
 * @param a number to be operated on
 * @param operation an opertaion to make on a and b(for example '+')
 * @param b number to be operated on
 * @return the result of the operation between a and b
*/
double Calculator::calculate(double a, char operation, double b) {
    switch (operation) {
        case '+':
            return add(a, b);
        case '-':
            return substract(a, b);
        case '*':
            return multiply(a, b);
        case '/':
            return divide(a, b);
        default:
            throw UndefinedMathOperationException();
    }
}
