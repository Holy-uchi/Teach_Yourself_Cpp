#include <iostream>

template <typename A, typename B, typename C>
auto fused_multiply_add(A a, B b, C c) {
  return a * b + c;
}

int main() {
  std::cout << fused_multiply_add<double, int, float>(1.23456, 2, 1.23456f)
            << std::endl;
}
