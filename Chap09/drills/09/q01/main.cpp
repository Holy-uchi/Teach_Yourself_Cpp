#include <iostream>

template <typename... Args>
void print_all(Args... args) {
  ((std::cout << args << " "), ...);
  std::cout << std::endl;
}

int main() { print_all(1, 3, "hoge", 3.14f); }
