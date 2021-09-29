#include "complex.h"

int main()
{
  complex_num::Complex z1{1, 2};
  complex_num::Complex z2{2, 1};
  complex_num::Complex res{0, 0};
  res = z1 + z2;
  std::cout << res << std::endl;
  res = z1 - z2;
  std::cout << res << std::endl;
  res = z1 * z2;
  std::cout << res << std::endl;
  res = z1 / z2;
  std::cout << res << std::endl;
  z1 += z2;
  std::cout << z1;
  
  return 0;
}