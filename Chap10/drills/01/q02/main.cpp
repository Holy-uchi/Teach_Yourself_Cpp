#include <iostream>

int main() {
  try {
    std::cout << "throw前" << std::endl;
    throw 0;
    std::cout << "throw後" << std::endl;
  } catch (int e) {
    std::cout << "int型の例外を補足: " << e << std::endl;
  }

  std::cout << "mainの最後" << std::endl;
}
