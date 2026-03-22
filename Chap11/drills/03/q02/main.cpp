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

  MoreDerived* pmd = dynamic_cast<MoreDerived*>(&d);

  if (pmd) {
    std::cout << "dynamic_cast成功" << std::endl;
  } else {
    std::cout << "dynamic_cast失敗" << std::endl;
  }
}
