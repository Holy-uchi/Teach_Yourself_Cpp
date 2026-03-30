#include <type_traits>

int main() {
  static_assert(std::is_same_v<int, int>);
  // static_assert(std::is_same_v<int, const int>); // コンパイル時に失敗
  // static_assert(std::is_same_v<int&, int>); // コンパイル時に失敗
}
