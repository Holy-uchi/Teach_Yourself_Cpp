#include <iostream>
#include <type_traits>

template <typename T>
std::enable_if_t<std::is_same_v<T, int>, void> f(T x) {
  std::cout << "int only: " << x << "\n";
}

int main() {
  f(10);
  // f(3.14);
}
