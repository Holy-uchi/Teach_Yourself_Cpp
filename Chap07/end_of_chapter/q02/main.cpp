#include <iostream>

class Base {
public:
  virtual ~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base {
public:
  ~Derived() { std::cout << "~Derived()" << std::endl; }
};

Base* alloc() { return new Derived{}; }

int main() {
  auto ptr = alloc();
  delete ptr;
}
