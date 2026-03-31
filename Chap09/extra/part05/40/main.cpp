// XXX:
#include <iostream>

template <typename T>
struct Printer {
  static void print(T x) { std::cout << x << "\n"; }
  static void print(const char* x) { std::cout << "overloaded: " << x << "\n"; }
};

template <>
struct Printer<const char*> {
  static void print(const char* x) {
    std::cout << "specialized: " << x << "\n";
  }
};

int main() {
  Printer<int>::print(
      "hello"); // 特別扱いしたい対象がクラス全体ではなく関数1個だけなら、オーバーロードの方が自然
  Printer<const char*>::print("world!");
}
