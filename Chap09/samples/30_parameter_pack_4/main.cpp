#include <iostream>

template <typename... Ts>
void print(Ts... args) {
  ((std::cout << args << " "), ...);
  std::cout << '\n';
}

int main() { print(1, 2.5, "hello", 'A'); }
