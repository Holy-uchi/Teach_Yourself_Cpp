
#include <iostream>
#include <utility>

void show_value_category(int& value) {
  static_cast<void>(value);
  std::cout << "参照" << std::endl;
}

void show_value_category(int&& value) {
  static_cast<void>(value);
  std::cout << "右辺値参照" << std::endl;
}

template <typename T>
void direct(T&& value) {
  show_value_category(value);
}

template <typename T>
void move(T&& value) {
  show_value_category(std::move(value));
}

template <typename T>
void forward(T&& value) {
  show_value_category(std::forward<T>(value));
}

int main() {
  int i = 0;

  forward(i);
  forward(0);
}
