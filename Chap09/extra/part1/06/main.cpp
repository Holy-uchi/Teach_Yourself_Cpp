// XXX:

#include <type_traits>

template <typename T>
void f1(T x) {
  static_assert(std::is_same_v<T, int>);
  static_assert(std::is_same_v<decltype(x), int>);
}

template <typename T>
void f2(T& x) {
  static_assert(std::is_same_v<T, const int>);
  static_assert(std::is_same_v<decltype(x), const int&>);
}

template <typename T>
void f3(T x) {
  static_assert(std::is_same_v<T, int*>);
  static_assert(std::is_same_v<decltype(x), int*>);
}

int main() {
  const int x = 42;
  int arr[3] = {1, 2, 3};

  auto a = x;
  auto& b = x;
  auto c = arr;
  // autoとtemplateはほぼ同じ

  static_assert(std::is_same_v<decltype(a), int>);
  static_assert(std::is_same_v<decltype(b), const int&>);
  static_assert(std::is_same_v<decltype(c), int*>);

  f1(x);
  f2(b);
  f3(arr);
}
