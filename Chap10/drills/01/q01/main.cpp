#include <iostream>

int main() {
  std::cout << "throw前" << std::endl;
  throw 0;
  std::cout << "throw後" << std::endl;
}
