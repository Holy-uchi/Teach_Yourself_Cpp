#include <iostream>

template <int N>
void show() {
  std::cout << N << std::endl;
}

int main() { show<5>(); }
