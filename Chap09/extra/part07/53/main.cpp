#include <iostream>
#include <type_traits>

template <typename T,
          typename = std::enable_if_t<std::is_floating_point_v<T>, T>>
void f(T x) {
  std::cout << x << "\n";
}

int main() { f(3.14); }
