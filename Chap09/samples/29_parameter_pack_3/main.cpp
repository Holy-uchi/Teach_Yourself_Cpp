#include <iostream>

template <typename... Ts>
auto sum(Ts... args) {
  return (... + args);
}

int main() {
  std::cout << sum(1, 2, 3, 4) << '\n';
  std::cout << sum(1.5, 2.5, 3.0) << '\n';
}
