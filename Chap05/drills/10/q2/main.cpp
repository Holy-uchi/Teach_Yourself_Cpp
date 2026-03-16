#include <iostream>

class A {
  int value = 0;

public:
  void set(int value) { this->value = value; }
  void foo();
  void bar();
};

void A::foo() {
  auto lambda = [this]() { std::cout << value << std::endl; };
  lambda();
}

void A::bar() {
  std::cout << "this->value = " << this->value << std::endl;
  auto lambda = [*this]() mutable {
    value = 42;
    std::cout << "value = " << value << std::endl;
  };
  lambda();
  std::cout << "this->value = " << this->value << std::endl;
}

int main() {
  A a;
  a.set(0);
  a.foo();
  a.bar();
}
