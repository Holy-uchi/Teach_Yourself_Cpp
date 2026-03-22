#include <iostream>
#include <typeinfo>

class Base {
public:
  virtual ~Base() {}
};

class Derived : public Base {};

void determine_class(const Base& base) {
  if (typeid(base) == typeid(Derived)) {
    std::cout << "Derived型です" << std::endl;
  } else if (typeid(base) == typeid(Base)) {
    std::cout << "Base型です" << std::endl;
  } else {
    std::cout << "Base型でもDerived型でもありません" << std::endl;
  }
}

int main() {
  Base base;
  Derived derived;

  determine_class(base);
  determine_class(derived);
}
