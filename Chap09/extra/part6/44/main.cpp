#include <type_traits>

int main() {
  int arr[3] = {1, 2, 3};
  static_assert(std::is_same_v<std::decay_t<decltype(arr)>, int*>);
  static_assert(std::is_same_v<std::decay_t<const int&>, int>);
}
