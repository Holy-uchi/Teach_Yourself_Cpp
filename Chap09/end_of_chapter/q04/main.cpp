#include <iostream>
#include <type_traits>

template <typename T>
T fuse_multiply_add(T a, T b, T c) {
  static_assert(std::is_integral<T>(), "整数型が必要です。");
  return a * b + c;
}

int main() {
  std::cout << fuse_multiply_add(1, 2, 3);
  // std::cout << fuse_multiply_add(1.1, 2.3, 3.4);
}
