#include <type_traits>
int main() {
  int x = 10;
  const int cx = 20;

  static_assert(std::is_same_v<decltype(x), int>);
  static_assert(std::is_same_v<decltype(cx), const int>);
  static_assert(std::is_same_v<decltype(x + 0),
                               int>); // prvalueならT
}
