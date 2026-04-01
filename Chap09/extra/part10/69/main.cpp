// XXX:
// C++17だとコンパイルできない。
// 推論ガイドが必要
// C++20だとコンパイルできる。

#include <utility>

template <typename T, typename U>
struct Pair {
  T first;
  U second;
};

int main() {
  std::pair p1{1, 2};
  std::pair p2{1, 2.0};
  static_cast<void>(p1);
  static_cast<void>(p2);

  Pair p3{1, 2};
  Pair p4{1, 2.0};

  static_cast<void>(p3);
  static_cast<void>(p4);
}
