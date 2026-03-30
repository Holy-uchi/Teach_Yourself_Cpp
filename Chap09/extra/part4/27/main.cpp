#include <iostream>

template <typename T>
void f(T) {
  std::cout << "template\n";
}

template <typename T>
void f(
    T*) { // 同じ名前fの、引数パターンが違う関数テンプレートなので、ただのオーバーロード
  std::cout << "pointer\n";
}

int main() {
  int x = 10;
  f(&x);
}
