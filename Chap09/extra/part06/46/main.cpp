#include <iostream>
#include <type_traits>

template <typename T>
std::enable_if_t<std::is_integral_v<T>, void> func(T x) {
  std::cout << x << "\n";
}

int main() {
  func(42);
  // func(3.14); コンパイルエラー
}
