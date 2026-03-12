#include <iostream>

int main() {
  int i = 0;

  int* iptr = &i;
  *iptr = 42;

  std::cout << i << std::endl;
}
