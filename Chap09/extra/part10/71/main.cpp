#include <array>

int main() {
  std::array<int, 3> a;
  std::array<int, 4> b;

  // aとbは別の型
  // static_assert(std::is_same_v<decltype(a), decltype(b)>);
  static_cast<void>(a);
  static_cast<void>(b);
}
