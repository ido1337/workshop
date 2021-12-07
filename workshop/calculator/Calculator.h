#pragma once
#include <exception>

// this class represents a simple calculator
class Calculator final {
public:

    /*
     * sum two numbers togther
     * @param a number to be added
     * @param b number to be added
     * @return a + b, sum of a and b
    */
    static double add(double a, double b) noexcept;


    /*
     * substract two numbers
     * @param a number to substract from
     * @param b number to be substracted
     * @return a - b, a substracted by b
    */
    static double substract(double a, double b) noexcept;


    /*
     * multiply two numbers
     * @param a number to be multiplied
     * @param b number to be multiplied
     * @return a * b, a mulyipled by b
    */
    static double multiply(double a, double b) noexcept;


    /*
     * divide two numbers
     * @param a number to divide
     * @param b number to be divider
     * @return a / b, a divided by b
    */
    static double divide(double a, double b);


    /*
     * calculate the result of an operation between a and b
     * @param a number to be operated on
     * @param operation an opertaion to make on a and b(for example '+')
     * @param b number to be operated on
     * @return the result of the operation between a and b
    */
    static double calculate(double a, char operation, double b);

    Calculator() = default;
    ~Calculator() = default;

    Calculator(const Calculator& other) = delete;
    Calculator(Calculator&& other) noexcept = delete;
    Calculator& operator=(const Calculator& other) = delete;
    Calculator& operator=(Calculator&& other) noexcept = delete;
};


// custom exception for division by zero
struct DivisionByZeroException : public std::exception
{
    const char* what() const throw ()
    {
        return "Division by zero Exception";
    }
};


// custom exception for undefined math operation
struct UndefinedMathOperationException : public std::exception
{
    const char* what() const throw ()
    {
        return "Undefined math operation Exception";
    }
};
