#include <iostream>

template <typename T>
auto fused_multiply_sub(T a, T b, T c) {
  return a * b - c;
}

int main() { std::cout << fused_multiply_sub(3, 6, 5) << std::endl; }
