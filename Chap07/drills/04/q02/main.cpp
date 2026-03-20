#include <iostream>

class Base {
  virtual void private_method();

public:
  void call_method();
};

void Base::private_method() {
  std::cout << "Base::private_method()" << std::endl;
}

void Base::call_method() { private_method(); }

class Derived : public Base {
  void private_method() override;
};

void Derived::private_method() {
  std::cout << "Derived::private_method()" << std::endl;
}

int main() {
  Derived derived;
  Base& base = derived;

  base.call_method();
}
