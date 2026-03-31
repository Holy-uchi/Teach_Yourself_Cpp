// XXX:
#include <type_traits>

template <typename T>
void f(T x) {
  // f(arr) のとき: Tはint*になる
  static_assert(std::is_same_v<T, int*>, "T should be int*");
  // decltype(x);
  // xも値引数なので型はint*
  static_assert(std::is_same_v<decltype(x), int*>, "T should be int*");
}

int main() {
  int arr[3] = {1, 2, 3};
  f(arr);
}
