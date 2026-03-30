#include <type_traits>
template <typename T>
void f(T&& x) {
  static_assert(std::is_same_v<T, int&>);
  static_assert(std::is_same_v<decltype(x), int&>);
}

int main() {
  int x = 10;

  f(x);
}
