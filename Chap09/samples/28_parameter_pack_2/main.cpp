#include <iostream>

void print_all() { std::cout << "(end)\n"; }

template <typename T, typename... Rest>
void print_all(T first, Rest... rest) {
  std::cout << first << '\n';
  print_all(rest...);
}

int main() { print_all(10, 2.5, "hello", 'A'); }
