#include <iostream>

template <typename... Ts>
auto sum(Ts... args) {
  return (... + args);
}

int main() { std::cout << sum(1, 2, 3, 4) << '\n'; }
