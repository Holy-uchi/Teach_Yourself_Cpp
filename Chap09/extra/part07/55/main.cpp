#include <iostream>
#include <type_traits>

template <typename T>
std::enable_if_t<std::is_integral_v<T>, void> func(T x) {
  std::cout << "int: " << x << "\n";
}

template <typename T>
std::enable_if_t<std::is_floating_point_v<T>, void> func(T x) {
  std::cout << "float: " << x << "\n";
}

int main() {
  func(3);
  func(3.14);
}
