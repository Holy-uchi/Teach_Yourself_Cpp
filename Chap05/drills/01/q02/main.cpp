#include <iostream>

int main() {
  int iarr[5] = {0, 1, 2, 3, 4};

  int* iptr = iarr;
  std::cout << *iptr << std::endl;
  iptr++;
  std::cout << *iptr << std::endl;
  iptr++;
  std::cout << *iptr << std::endl;
  iptr++;
  std::cout << *iptr << std::endl;
  iptr++;
  std::cout << *iptr << std::endl;
}
