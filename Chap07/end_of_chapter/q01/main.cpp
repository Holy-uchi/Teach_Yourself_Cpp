#include <iostream>

class Base {
public:
  virtual void method() { std::cout << "Base.method" << std::endl; }
};

class Derived : public Base {
public:
  void method() override { std::cout << "Derived.method" << std::endl; }
};

int main() {
  Derived derived;
  derived.method();

  Base& base = derived;
  base.method();
}
