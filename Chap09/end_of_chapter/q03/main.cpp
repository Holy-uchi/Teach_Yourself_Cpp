#include <iostream>
#include <type_traits>
#include <utility>

template <typename T>
void print_one(T&& value) {
  static_assert(!std::is_lvalue_reference_v<T>);
  std::cout << "右辺値参照: " << value << std::endl;
}

template <typename T>
void print_one(T& value) {
  std::cout << "左辺値参照: " << value << std::endl;
}

template <typename... Ts>
void print_all(Ts&&... args) {
  (print_one(std::forward<Ts>(args)), ...);
}

template <typename... Ts>
void log_info(Ts&&... args) {
  std::cout << "[INFO] " << std::endl;
  print_all(std::forward<Ts>(args)...);
}

int main() {
  int i = 42;
  log_info(1, i);
}
