#include <iostream>

class Base {
public:
  virtual void method() { std::cout << "Base.method()" << std::endl; }
};

class Derived : public Base {
public:
  void method() final { std::cout << "Derived.method()" << std::endl; }
};

class MoreDerived : public Derived {
public:
  // void method() override {}
};

int main() {
  Derived derived;
  derived.method();
}
