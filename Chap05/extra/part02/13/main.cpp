#include <iostream>
#include <memory>

struct Base {
  virtual ~Base() { std::cout << "Base destruct\n"; }
};

struct Derived : Base {
  ~Derived() override { std::cout << "Derived destruct\n"; }
};

int main() { std::unique_ptr<Base> p = std::make_unique<Derived>(); }
