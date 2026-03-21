#include <iostream>

template <typename T>
void foo(T& value) {
  static_cast<void>(value);
  std::cout << "void foo(T& value)" << std::endl;
}

template <typename T>
void foo(T&& value) {
  static_cast<void>(value);
  std::cout << "void foo(T&& value)" << std::endl;
}

int main() {
  int i = 0;

  foo(i);

  foo(0);
}
