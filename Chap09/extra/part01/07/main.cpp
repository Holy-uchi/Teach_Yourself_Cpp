// XXX:

#include <initializer_list>
#include <type_traits>
template <typename T>
void f(T x) {
  static_assert(std::is_same_v<T, std::initializer_list<int>>);
  static_assert(std::is_same_v<decltype(x), std::initializer_list<int>>);
}

int main() {
  // f({1, 2, 3});

  auto x = {1, 2, 3};
  std::initializer_list<int> y = {1, 2, 3};

  static_cast<void>(x);
  static_cast<void>(y);

  // 明示的にinitializer_listを渡すと通る
  f<std::initializer_list<int>>({1, 2, 3});
}
