#include <iostream>

int main() {
  auto dephault = std::cout.flags();

  std::cout.setf(std::ios::scientific);

  std::cout.setf(std::ios::hex, std::ios::basefield);

  std::cout << 123.456f << std::endl;
  std::cout << 123456 << std::endl;

  std::cout.flags(dephault);

  std::cout << 123.456f << std::endl;
  std::cout << 123456 << std::endl;
}
