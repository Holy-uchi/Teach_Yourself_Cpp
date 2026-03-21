#include <iostream>

template <typename Type>
Type fused_multiply_add(Type a, Type b, Type c) {
  return a * b + c;
}

int main() {
  std::cout << fused_multiply_add(1, 2, 3) << std::endl;

  std::cout << fused_multiply_add(1.23456f, 1.23456f, 1.23456f) << std::endl;

  std::cout << fused_multiply_add(1.23456, 1.23456, 1.23456) << std::endl;
}
