#include <iostream>

template <typename... Ts>
void show_count(Ts... args) {
  std::cout << "number of types: " << sizeof...(Ts) << '\n';
  std::cout << "number of args: " << sizeof...(args) << '\n';
}

int main() {
  show_count();
  show_count(10);
  show_count(10, 3.14, "hello");
}
