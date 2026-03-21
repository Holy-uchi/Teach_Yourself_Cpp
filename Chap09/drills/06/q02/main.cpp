#include <iostream>

template <auto N>
void show() {
  std::cout << N << std::endl;
}

int main() {
  show<5>();
  show<3.14159>();
  show<'a'>();
  show<true>();
}
