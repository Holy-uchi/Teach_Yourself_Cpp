#include <iostream>

int main() {
  auto lambda = [](const auto& arg) { std::cout << arg << std::endl; };

  lambda(3);
  lambda(3.14159265);
  lambda(1.234f);
  lambda("Hello, World!");
}
