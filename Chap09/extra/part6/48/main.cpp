#include <iostream>
#include <type_traits>

template <typename T>
void func(T x) {
  if constexpr (std::is_integral_v<T>) {
    std::cout << "int: " << x << "\n";
  } else if constexpr (std::is_floating_point_v<T>) {
    std::cout << "float: " << x << "\n";
  }
}

int main() {
  func(3);
  func(3.14f);
}
