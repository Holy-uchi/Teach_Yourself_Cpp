#include <iostream>

template <typename R, typename A, typename B, typename C>
R fused_multiply_add(A a, B b, C c) {
  return static_cast<R>(a * b + c);
}

int main() {
  std::cout << fused_multiply_add<float, double>(1.23456f, 2, 3) << std::endl;
}
