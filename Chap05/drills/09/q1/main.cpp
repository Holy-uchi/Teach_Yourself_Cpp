#include <iostream>

int add(int a, int b) { return a + b; }

int main() {
  int (*func)(int, int);
  func = &add;

  std::cout << func(1, 2) << std::endl;
}
