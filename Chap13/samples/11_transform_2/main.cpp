#include <cstddef>
#include <iostream>
#include <string>

int main() {
  std::cout << std::stoi("-10") << std::endl;

  std::cout << std::stoul("deadbeef", nullptr, 16) << std::endl;

  std::cout << std::stol("0755", nullptr, 0) << std::endl;

  std::cout << std::stod("3.14159265") << std::endl;

  std::size_t idx = 0;

  int integer = std::stoi("42.195", &idx);

  std::cout << integer << "; idx = " << idx << std::endl;
}
