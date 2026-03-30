#include <type_traits>

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, T> func(T a, T b) {
  return a + b;
}

int main() {
  func(1, 2);
  func(3.14, 6.28);
  // std::string s1 = "a", s2 = "b";
  // func(a,b); // コンパイルエラー
}
