#include <concepts>
#include <iostream>

template <std::integral T>
void f(T x) {
  std::cout << ++x << "\n";
}

int main() {
  f(42);
  // f(3.14);
}
