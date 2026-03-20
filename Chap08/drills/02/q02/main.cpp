#include <iostream>

int main() {
  std::cout.width(8);
  std::cout.fill('-');
  std::cout.setf(std::ios::oct, std::ios::basefield);

  std::cout << 8 << std::endl;
}
