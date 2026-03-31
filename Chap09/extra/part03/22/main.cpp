#include <type_traits>
struct S {
  int value;
};

S s{10};

decltype(auto) get(S& obj) {
  return (obj.value); // autoだとmemberをコピーして返す
}

int main() {
  static_assert(std::is_same_v<decltype(get(s)), int&>);

  get(s) = 42; // 参照が変えるので代入できる
  static_assert(std::is_same_v<decltype((s.value)), int&>);
}
