#include <iostream>

template <typename T>
concept Addable = requires(T a, T b) { a + b; };

template <Addable T>
T add(T a, T b) {
  return a + b;
}

int main() { std::cout << add(3, 5) << "\n"; }
