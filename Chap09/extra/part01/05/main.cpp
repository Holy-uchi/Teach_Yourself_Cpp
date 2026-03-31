#include <type_traits>
int foo(int) { return 0; }

template <typename T>
void f(T x) {
  static_assert(std::is_same_v<T, int*> || std::is_same_v<T, int (*)[3]> ||
                std::is_same_v<T, int (*)(int)>);

  static_assert(std::is_same_v<decltype(x), int*> ||
                std::is_same_v<decltype(x), int (*)[3]> ||
                std::is_same_v<decltype(x), int (*)(int)>);
}

int main() {
  int arr[3] = {1, 2, 3};
  f(arr);
  f(&arr[0]);
  f(foo);
}
