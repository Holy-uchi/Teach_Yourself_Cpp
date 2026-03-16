#include <iostream>

class A {
  int value;

public:
  int& get_value() { return this->value; }
  void set_valie(int value) { this->value = value; }
  const int& get_value() const { return this->value; }
};

int main() {
  const A a{};
  auto& b = a.get_value();

  std::cout << b << std::endl;
}
