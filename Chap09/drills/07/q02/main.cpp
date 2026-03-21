#include <iostream>
#include <string>
#include <utility>

template <typename T>
void show_value(T&& value) {
  std::cout << "右辺値参照: " << value << std::endl;
}

template <typename T>
void show_value(T& value) {
  std::cout << "左辺値参照: " << value << std::endl;
}

template <typename T>
void forward(T&& value) {
  show_value(std::forward<T>(value));
}

int main() {
  int i = 42;

  forward(i);
  forward(0);

  std::string str = "Hello, world!";

  forward(str);
  forward("Hello, forward!"); // これは左辺値参照になっちゃうか？
}
