#include "complex.h"

namespace complex_num 
{
  Complex& Complex::operator+=(const Complex& c)
  {
    real_ += c.real_;
    imaginary_ += c.imaginary_;
    return *this;
  }

  Complex& Complex::operator-=(const Complex& c)
  {
    real_ -= c.real_;
    imaginary_ -= c.imaginary_;
    return *this;
  }

  Complex& Complex::operator*=(const Complex& c)
  {
    double real = real_ * c.real_ - imaginary_*c.imaginary_;
    double imaginary = real_ * c.imaginary_ + imaginary_ * c.real_;
    real_ = real;
    imaginary_ = imaginary;
    return *this;
  }

  Complex& Complex::operator/=(const Complex& c)
  {
    Complex number = Complex(*this) * Complex(c.real_, c.imaginary_);
    double dn = c.real_ * c.real_ + c.imaginary_ * c.imaginary_;
    real_ = number.real_ / dn;
    imaginary_ = number.imaginary_ / dn;
    return *this;
  }

  Complex Complex::operator+(const Complex& c) const
  { return Complex(*this) += c; }

  Complex Complex::operator-(const Complex& c) const
  { return Complex(*this) -= c; }

  Complex Complex::operator*(const Complex& c) const
  { return Complex(*this) *= c; }

  Complex Complex::operator/(const Complex& c) const
  { return Complex(*this) /= c; }

  ostream& operator<<(ostream& os, const Complex c)
  {
    double real = c.get_real();
    double imaginary = c.get_imaginary();

    os << real;
    if (imaginary < 0)
      os << imaginary << " i ";
    else if (imaginary > 0)
      os << " + " << imaginary << " i ";
    return os;    
  }
}