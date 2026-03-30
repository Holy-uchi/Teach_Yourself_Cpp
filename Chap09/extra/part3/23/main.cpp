#include <type_traits>
int x = 10;

int& g() { return x; }
int h() { return x; }

template <typename F>
decltype(auto) wrapper(F f) {
  return f();
}

int main() {
  static_assert(std::is_same_v<decltype(wrapper(g)), int&>);
  static_assert(std::is_same_v<decltype(wrapper(h)), int>);
}
