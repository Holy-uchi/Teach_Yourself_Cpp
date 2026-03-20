#include <iostream>

int main() {
  std::cout.setf(std::ios::scientific, std::ios::floatfield);
  double pi = 3.14159265;
  std::cout << pi << std::endl;
}
