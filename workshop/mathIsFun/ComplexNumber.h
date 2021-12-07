#pragma once
#include <ostream>


class ComplexNumber final{
public:
    /*
     * default constructor, initialize number to be zero
    */
    explicit ComplexNumber();


    /*
     * gets real and imaginary number for new complex number
     * @param real real number
     * @imaginary imaginary number
    */
    explicit ComplexNumber(const double real, const double imaginary);

    /*
     * default destructor
    */
    ~ComplexNumber() = default;


    /*
     * getter for the real number part
     * @return the real number part from the complex number
    */
    double getReal() const noexcept;


    /*
     * setter for the real number part
     * @parram real new real number part of the complex number
    */
    void setReal(const double real) noexcept;


    /*
     * getter for the imaginary number part
     * @return the imaginary number part from the complex number
    */
    double getImaginary() const noexcept;
 

    /*
     * setter for the imaginary number part
     * @parram imaginary new imaginary number part of the complex number
    */
    void setImaginary(const double imaginary) noexcept;


    /*
     * operator which checks if complex numbers are equal
     * @param other complex number to be compared with this
     * @return true if both numbers are equal else false
    */
    bool operator==(const ComplexNumber& other) const noexcept;


    /*
     * operator which sum two complex numbers
     * @param other complex number to be sum with this
     * @return sum of this and other
    */
    ComplexNumber operator+(const ComplexNumber& other) const noexcept;


    /*
     * operator which substract two complex numbers
     * @param other complex number to be substracted from this
     * @return substraction of this with other
    */
    ComplexNumber operator-(const ComplexNumber& other) const noexcept;


    /*
     * operator which multiply two complex numbers
     * @param other complex number to be multipy with this
     * @return multiply of this and other
    */
    ComplexNumber operator*(const ComplexNumber& other) const noexcept;
private:
    friend std::ostream& operator<<(std::ostream& strm, const ComplexNumber& num) noexcept;


    /*
     * checks if complex numbers are equal
     * @param other complex number to be compared with this
     * @return true if both numbers are equal else false
    */
    bool equal(const ComplexNumber& other) const noexcept;


    /*
     * sum two complex numbers
     * @param other complex number to be sum with this
     * @return sum of this and other
    */
    ComplexNumber add(const ComplexNumber& other) const noexcept;


    /*
     * substract two complex numbers
     * @param other complex number to be substracted from this
     * @return substraction of this with other
    */
    ComplexNumber substract(const ComplexNumber& other) const noexcept;


    /*
     * multiply two complex numbers
     * @param other complex number to be multipy with this
     * @return multiply of this and other
    */
    ComplexNumber multiply(const ComplexNumber& other) const noexcept;

private:
    double m_real;
    double m_imaginary;
};
