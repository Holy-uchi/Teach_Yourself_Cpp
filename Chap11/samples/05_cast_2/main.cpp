#include <iostream>

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

  std::cout << pb->get_class_name() << std::endl;

  Derived* pd = dynamic_cast<Derived*>(pb);

  if (pd) {
    std::cout << pd->get_class_name() << std::endl;
  } else {
    std::cout << "dynamic_cast失敗" << std::endl;
  }

  MoreDerived* pmd = dynamic_cast<MoreDerived*>(pb);

  if (pmd) {
    std::cout << pmd->get_class_name() << std::endl;
  } else {
    std::cout << "dynamic_cast失敗" << std::endl;
  }
}
