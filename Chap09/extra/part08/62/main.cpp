#include <concepts>
#include <iostream>

template <std::integral T>
void f(T) {
  std::cout << "integral\n";
}

template <std::floating_point T>
void f(T) {
  std::cout << "floating\n";
}

int main() {
  f(10);
  f(3.14);
  f(true);

  // template <std::integral T>とtemplate <std::floating_point
  // T>は別の宣言なので共存可能。
  // また、条件も排他的なので呼び出し時に曖昧になることもない。
  // boolはstd::integralを満たすので、integralの方で解決される
}
