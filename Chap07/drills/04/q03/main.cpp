#include <iostream>

class Base {
public:
  virtual ~Base() { std::cout << "Base::~Base()" << std::endl; }
};

class Derived : public Base {
public:
  ~Derived() override { std::cout << "Derived::~Derived()" << std::endl; }
};

Base* alloc() { return new Derived{}; }

int main() {
  auto base_ptr = alloc();
  delete base_ptr;
}
