#include <iostream>

template <typename T>
void print(T x) {
  std::cout
      << x
      << "\n"; // どうせcoutのオーバーロードがあるかどうかで決まるので、直接std::coutを書いた方がいい。
  // もしくは、ユーザー定義クラスを作るなら、<<をそれ用にオーバーロードする
}

int main() {}
