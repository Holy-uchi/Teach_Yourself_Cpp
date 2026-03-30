#include <iostream>

void f(double) { std::cout << "double\n"; }

template <typename T>
void f(T) {
  std::cout << "template\n";
}

int main() {
  f(10);
  // f(double)は、10 => 10.0に暗黙の型変換をしないと呼べない。
  // f(T)はなんでも受けられるのでf(int)が存在し、優先される
}
