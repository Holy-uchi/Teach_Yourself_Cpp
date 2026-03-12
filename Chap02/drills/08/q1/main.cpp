#include <iostream>

int main() {
  auto show_value = [](int a) { std::cout << a << std::endl; };

  show_value(42);
}
