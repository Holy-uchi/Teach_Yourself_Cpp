#include <iostream>

template <typename T>
void f(T) {
  std::cout << "general\n";
}

template <>
void f<int>(int) {
  std::cout << "specialized\n";
}

int main() {
  f(10);   // specializedが呼ばれる
  f(3.14); // 特殊化がないので、generalが呼ばれる
}
