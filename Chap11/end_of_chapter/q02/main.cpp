#include <iostream>
#include <ostream>

class Base {
public:
  virtual ~Base() {}

  const char* get_class_name() const { return "Base"; }
};

class Derived : public Base {
public:
  const char* get_class_name() const { return "Derived"; }
};

class MoreDerived : public Derived {
public:
  const char* get_class_name() const { return "MoreDerived"; }
};

int main() {
  Derived d;

  Base& rb = d;

  try {
    Derived& rd = dynamic_cast<Derived&>(rb);
    std::cout << "dyamic_cast成功" << std::endl;
    static_cast<void>(rd);
  } catch (std::bad_cast bc) {
    std::cout << "dyamic_cast失敗" << std::endl;
  }
}
