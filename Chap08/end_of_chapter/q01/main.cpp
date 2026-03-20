#include <iomanip>
#include <iostream>

int main() {
  std::cout << std::hex;
  std::cout << std::setw(16);
  std::cout << std::setfill('=');

  std::cout << 2145 << std::endl;
}
