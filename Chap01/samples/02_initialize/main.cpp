#include <iostream>
int main() {
  int a(0);
  int b = 1;
  int c{2};
  int d = {3};

  std::cout << a << b << c << d << std::endl;
}
