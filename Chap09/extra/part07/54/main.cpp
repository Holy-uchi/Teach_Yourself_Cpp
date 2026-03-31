#include <iostream>
#include <type_traits>

template <typename T, std::enable_if_t<std::is_integral_v<T>, int> = 0>
void f(T x) {
  std::cout << x << "\n";
}

int main() { f(3); }
