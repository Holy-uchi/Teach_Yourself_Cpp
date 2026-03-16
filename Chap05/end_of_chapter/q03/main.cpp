#include <iostream>

int add(const int& a, const int& b) { return a + b; }
int add(int&& a, int&& b) { return a + b; }

int main() {
  int x = 1;
  int y = 2;
  std::cout << add(x, y) << std::endl;
  std::cout << add(1, 3) << std::endl;
}
