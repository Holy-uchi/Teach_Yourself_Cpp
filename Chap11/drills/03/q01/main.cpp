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

  Base* pb = &d;

  Derived* pd = static_cast<Derived*>(pb);

  if (pd) {
    std::cout << "static_cast成功" << std::endl;
  } else {
    std::cout << "static_cast失敗" << std::endl;
  }
}
