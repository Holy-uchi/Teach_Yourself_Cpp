#include <type_traits>
int main() {
  int x = 10;

  static_assert(
      std::is_same_v<
          decltype(x),
          int>); // 変数名そのものを渡したときは、特別に宣言型をそのまま返す
  static_assert(
      std::is_same_v<decltype((x)), int&>); // (x)という式が返すのはlvalue
}
