#include <iostream>

template <typename T>
void show_value(const T& value) {
  std::cout << "value=" << value << std::endl;
}

int main() {
  std::string str = "Hello, World!";
  show_value(str);

  show_value(7);
}
