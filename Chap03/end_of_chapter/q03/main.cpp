#include <iostream>

class Base {
  int value = 0;

public:
  explicit Base(int value);
  virtual void print_value();
};

Base::Base(int value) : value(value) {}
void Base::print_value() {
  std::cout << "Baseのprint_value: " << this->value << std::endl;
}

class Derived : public Base {
public:
  explicit Derived(int value);
  using Base::print_value;
  void print_value(int val);
};

Derived::Derived(int value) : Base(value) {}

void Derived::print_value(int val) {
  std::cout << "Derivedのprint_value: " << val << std::endl;
}

int main() {

  Derived d1{1};
  d1.print_value(2);
  d1.print_value();
}
