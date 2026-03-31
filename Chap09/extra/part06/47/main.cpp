#include <cstddef>
#include <iostream>
#include <type_traits>

template <typename T>
std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>, void> func(T x) {
  std::cout << "signed int: " << x << "\n";
}

int main() {
  func(5);

  // unsigned型を渡すとコンパイルできない
  // std::size_t a = 6;
  // func(a);
}
