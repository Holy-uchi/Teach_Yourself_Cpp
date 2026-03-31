// XXX:
#include <type_traits>

template <typename T>
void f(T& x) {
  // C配列でも、参照で受けると崩壊しない
  static_assert(std::is_same_v<T, int[3]>, " T should be array of 3 int");

  static_assert(std::is_same_v<decltype(x), int (&)[3]>,
                "T should be array of 3 int");
}

int main() {
  // C配列
  int arr[3] = {1, 2, 3};
  // C++のstd::arrayは軽量なコンテナ
  // std::array<int, 3>
  f(arr);
}
