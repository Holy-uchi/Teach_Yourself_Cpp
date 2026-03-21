#include <iostream>

template <typename T>
void show(T input);

template <>
void show<std::string>(std::string input) {
  std::cout << "std::stringで明示的特殊化した関数: value=" << input
            << std::endl;
}

template <typename T>
void show(T input) {
  std::cout << "value=" << input << std::endl;
}

int main() {
  show<std::string>("Hello, world!");
  show<int>(10);
}
