#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

namespace complex_num 
{
  using std::ostream;
  using std::iostream;

  class Complex
  {
    private:
      double real_;
      double imaginary_;
    public:
      Complex(double real, double imaginary) : real_(real), imaginary_(imaginary) {}
      ~Complex () {};

      Complex& operator=(const Complex& c);

      Complex operator+(const Complex& c) const;
      Complex operator-(const Complex& c) const;
      Complex operator*(const Complex& c) const;
      Complex operator/(const Complex& c) const;

      bool operator==(const Complex& c) const;
      bool operator!=(const Complex& c) const;

      Complex& operator+=(const Complex& c);
      Complex& operator-=(const Complex& c);
      Complex& operator*=(const Complex& c);
      Complex& operator/=(const Complex& c);

      double get_real() const
      { return real_; }

      double get_imaginary() const
      { return imaginary_; }
  };

  ostream& operator<< (ostream& os, const Complex c);
}
//====================================================================================

#endif