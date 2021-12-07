#include "ComplexNumber.h"
#include <string>

/*
 * default constructor, initialize number to be zero
*/
ComplexNumber::ComplexNumber() :
    m_real(0), 
    m_imaginary(0)
{}


/*
 * gets real and imaginary number for new complex number
 * @param real real number
 * @imaginary imaginary number
*/
ComplexNumber::ComplexNumber(const double real, const double imaginary) :
    m_real(real),
    m_imaginary(imaginary)
{}


/*
 * getter for the real number part
 * @return the real number part from the complex number
*/
double ComplexNumber::getReal() const noexcept {
    return m_real;
}


/*
 * setter for the real number part
 * @parram real new real number part of the complex number
*/
void ComplexNumber::setReal(const double real) noexcept {
    m_real = real;
}


/*
 * getter for the imaginary number part
 * @return the imaginary number part from the complex number
*/
double ComplexNumber::getImaginary() const noexcept {
    return m_imaginary;
}


/*
 * setter for the imaginary number part
 * @parram imaginary new imaginary number part of the complex number
*/
void ComplexNumber::setImaginary(const double imaginary) noexcept {
    m_imaginary = imaginary;
}


/*
 * checks if complex numbers are equal
 * @param other complex number to be compared with this
 * @return true if both numbers are equal else false
*/
bool ComplexNumber::equal(const ComplexNumber& other) const noexcept {
    return (this->m_real == other.m_real) && (this->m_imaginary == other.m_imaginary);
}


/*
 * sum two complex numbers
 * @param other complex number to be sum with this
 * @return sum of this and other
*/
ComplexNumber ComplexNumber::add(const ComplexNumber& other) const noexcept {
    return ComplexNumber(this->m_real + other.m_real, this->m_imaginary + other.m_imaginary);
}


/*
 * substract two complex numbers
 * @param other complex number to be substracted from this
 * @return substraction of this with other
*/
ComplexNumber ComplexNumber::substract(const ComplexNumber& other) const noexcept {
    return ComplexNumber(this->m_real - other.m_real, this->m_imaginary - other.m_imaginary);
}


/*
 * multiply two complex numbers
 * @param other complex number to be multipy with this
 * @return multiply of this and other
*/
ComplexNumber ComplexNumber::multiply(const ComplexNumber& other) const noexcept {
    return ComplexNumber(this->m_real * other.m_real - this->m_imaginary * other.m_imaginary,
                         this->m_imaginary * other.m_imaginary + this->m_imaginary * other.m_real);
}


/*
 * operator which checks if complex numbers are equal
 * @param other complex number to be compared with this
 * @return true if both numbers are equal else false
*/
bool ComplexNumber::operator==(const ComplexNumber& other) const noexcept {
    return equal(other);
}


/*
 * operator which sum two complex numbers
 * @param other complex number to be sum with this
 * @return sum of this and other
*/
ComplexNumber ComplexNumber::ComplexNumber::operator+(const ComplexNumber& other) const noexcept {
    return add(other);
}


/*
 * operator which substract two complex numbers
 * @param other complex number to be substracted from this
 * @return substraction of this with other
*/
ComplexNumber ComplexNumber::ComplexNumber::operator-(const ComplexNumber& other) const noexcept {
    return substract(other);
}


/*
 * operator which multiply two complex numbers
 * @param other complex number to be multipy with this
 * @return multiply of this and other
*/
ComplexNumber ComplexNumber::ComplexNumber::operator*(const ComplexNumber& other) const noexcept {
    return multiply(other);
}



/*
 * gets visual representation of complex number
 * @param strm stream to store in the representation of the complex number
 * @param num complex number to get representation of
 * @return stream which represents the complex number
*/
std::ostream& operator<<(std::ostream& strm, const ComplexNumber& num) noexcept {
    std::string real = std::to_string(num.m_real);
    std::string imaginary = std::to_string(abs(num.m_imaginary)) + "i"; 
    std::string imaginary_sign = (num.m_imaginary < 0 ? " - " : " + ");
    if ((num.m_real == 0) && (num.m_imaginary == 0)) {
        strm << "0";
    }
    else if (num.m_real == 0) {
        strm << imaginary;
    }
    else if (num.m_imaginary == 0) {
        strm << real;
    }
    else {
        strm << real << imaginary_sign << imaginary;
    }
    return strm;
}
