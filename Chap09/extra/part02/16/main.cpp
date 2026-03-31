#include <iostream>
#include <utility>

void g(int& x) {
  std::cout << "lvalue\n";
  static_cast<void>(x);
}

void g(int&& x) {
  std::cout << "rvalue\n";
  static_cast<void>(x);
}

template <typename T>
void wrapper(T&& x) {
  auto y = std::forward<T>(x); // ←ここが問題
  g(std::forward<T>(
      y)); // 結局関数の実引数で渡すときにstd::forwardする必要がある。
}

int main() {
  int ft = 42;
  wrapper(ft);
  wrapper(10);
}
