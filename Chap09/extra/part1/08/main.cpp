#include <type_traits>

template <typename T>
void f1(T&& x) {
  static_assert(std::is_same_v<T, int (&)[3]>);
  // arrを左辺値として受ける場合参照になる。
  // 配列を参照で受けるので崩壊しないということか？
  static_assert(std::is_same_v<decltype(x), int (&)[3]>);
  // int (&)[3] && => int (&)[3]
}

template <typename T>
void f2(T&& x) {
  static_assert(std::is_same_v<T, const int&>);
  // cxはconst intの左辺値
  // T&&がforwarding referenceとして働き、Tは左辺値参照として推論
  // よってTはconst int&になる

  static_assert(std::is_same_v<decltype(x), const int&>);
  // const int& && => const int&
}

int main() {
  int arr[3] = {1, 2, 3};
  const int cx = 10;

  f1(arr);
  f2(cx);
}
