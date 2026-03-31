#include <type_traits>
int main() {
  int x = 10;
  int& ref = x;

  auto a = ref;
  auto& b = ref;

  static_assert(std::is_same_v<decltype(a), int>);  // autoは値コピー
  static_assert(std::is_same_v<decltype(b), int&>); // auto&は参照
}
