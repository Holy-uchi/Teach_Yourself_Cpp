#include <iostream>

class A {
public:
  template <typename T>
  void print_value(T value);
};

template <typename T>
void A::print_value(T value) {
  std::cout << value << std::endl;
}

int main() {
  A a;
  a.print_value(3);
}
