#include <type_traits>
template <typename T>
void f1(T x) {
  static_assert(std::is_same_v<T, int>, "T should be int");
  static_assert(std::is_same_v<decltype(x), int>, "x should be int");
}

template <typename T>
void f2(T& x) {
  static_assert(std::is_same_v<T, int> || std::is_same_v<T, const int>,
                "T should be int or const int");
  static_assert(std::is_same_v<decltype(x), int&> ||
                    std::is_same_v<decltype(x), const int&>,
                "x should be int& or const int&");
}

template <typename T>
void f3(const T& x) {
  static_assert(std::is_same_v<T, int>, "T should be int");
  static_assert(std::is_same_v<decltype(x), const int&>,
                "x should be const int&");
}

template <typename T>
void f4(T&& x) {
  // 左辺値ならTは参照型、右辺値ならTはそのまま
  static_assert(std::is_same_v<T, int&> || std::is_same_v<T, const int&> ||
                    std::is_same_v<T, int>,
                "T should be int&, const int& or int");
  static_assert(std::is_same_v<decltype(x), int&> ||
                    std::is_same_v<decltype(x), const int&> ||
                    std::is_same_v<decltype(x), int&&>,
                "x should be int");
}

int main() {
  int x = 10;
  const int cx = 20;

  f1(x);
  f2(x);
  f3(x);
  f4(x);

  f1(cx);
  f2(cx);
  f3(cx);
  f4(cx);

  f4(42);
}
