#include <iostream>

int main() {
  const int i = 42;
  const int& r = i;
  std::cout << r << std::endl;
}
