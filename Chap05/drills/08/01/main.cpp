#include <iostream>
#include <ostream>
#include <utility>

int add(int&& a, int&& b) { return a + b; }

int main() {
  int a = 10;
  int b = 20;

  int c = add(std::move(a), std::move(b));
  std::cout << c << std::endl;
}
