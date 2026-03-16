#include <iostream>
void clear(int& target) { target = 0; }

int main() {
  int ft = 42;
  std::cout << "ft: " << ft << std::endl;

  clear(ft);
  std::cout << "ft: " << ft << std::endl;
}
