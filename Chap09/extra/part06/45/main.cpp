#include <iostream>
#include <type_traits>

template <bool IsInt>
using Number_t = std::conditional_t<IsInt, int, double>;

int main() {
  Number_t<true> a{3};
  Number_t<false> b{3.14};

  std::cout << a << "\n";
  std::cout << b << "\n";
}
