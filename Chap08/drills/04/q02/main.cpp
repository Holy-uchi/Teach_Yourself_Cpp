#include <iomanip>
#include <iostream>

int main() {
  std::cout << std::setw(8) << std::setfill('0');
  std::cout << 1234 << std::endl;
}
