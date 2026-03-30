// XXX:

#include <iostream>
#include <utility>

void process(int& x) {
  std::cout << "lvalue\n";
  static_cast<void>(x);
}

void process(int&& x) {
  std::cout << "rvalue\n";
  static_cast<void>(x);
}

template <typename T>
void wrapper(T&& x) {
  process(std::forward<T>(x)); // 問題あり
}

int main() {
  int x = 42;

  wrapper(x);
  wrapper(42);
}
