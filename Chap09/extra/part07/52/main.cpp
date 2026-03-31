#include <type_traits>

template <typename T>
std::enable_if_t<std::is_integral_v<T>, T> func(T x) {
  return ++x;
}

int main() {
  func(42);
  // func(3.14); // コンパイルエラー
}
