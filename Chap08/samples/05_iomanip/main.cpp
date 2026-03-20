#include <iomanip>
#include <iostream>

int main() {
  std::cout << std::hex << 1234 << std::endl;

  std::cout << std::setprecision(6) << 1234.5678f << std::endl;

  std::cout.setf(std::ios::boolalpha);
  std::cout << std::noboolalpha << true << std::endl;
}
