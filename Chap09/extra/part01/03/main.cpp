#include <type_traits>
template <typename T>
void f1(T x) {
  // 可変な値としてコピー
  static_assert(std::is_same_v<T, int>, "T should be int");
  static_assert(std::is_same_v<decltype(x), int>, "x should be int");
}
template <typename T>
void f2(T& x) {
  // T& は元がconstならconstがつくし、そうでないならつかない
  static_assert(std::is_same_v<T, const int>, "T should be const int");
  static_assert(std::is_same_v<decltype(x), const int&>,
                "x should be const int&");
}
template <typename T>
void f3(const T& x) {
  // const T&は元の型に関係なくconst をつける(厳しくする分にはok)
  static_assert(std::is_same_v<T, int>, "T should be int");
  static_assert(std::is_same_v<decltype(x), const int&>,
                "x should be const int&");
}

int main() {
  const int x = 42;
  int y = 42;

  f1(x);
  f2(x);
  f3(x);

  f1(y);
  // f2(y); // static_assertで落ちる
  f3(y);
}
