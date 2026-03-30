#include <type_traits>
template <typename T>
void f(T&& x) {
  // 右辺値が渡されると、Tは値型になる。
  // int && => int&&
  static_assert(std::is_same_v<T, int>);
  static_assert(std::is_same_v<decltype(x), int&&>);
}

int main() { f(42); }
