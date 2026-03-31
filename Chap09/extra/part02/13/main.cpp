#include <iostream>

void g(int& x) {
  std::cout << "lvalue\n";
  static_cast<void>(x);
}

void g(int&& x) {
  std::cout << "rvalue\n";
  static_cast<void>(x);
}

template <typename T>
void f1(T&& x) {
  g(x);
}

template <typename T>
void f2(T&& x) {
  g(std::forward<T>(x));
}

int main() {
  int x = 10;

  f1(x);
  f1(10);

  f2(x);
  f2(10);
}
