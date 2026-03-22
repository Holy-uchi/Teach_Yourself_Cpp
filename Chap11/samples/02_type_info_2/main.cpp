#include <iostream>
#include <typeinfo>

class Base {};

class Derived : public Base {};

class Composed {
  Base base;

public:
  void nonsence() { static_cast<void>(this->base); }
};

int main() {
  if (typeid(Base) == typeid(Derived)) {
    std::cout << "BaseとDerivedは同じクラスです" << std::endl;
  } else {
    std::cout << "BaseとDerivedは異なるクラスです" << std::endl;
  }

  if (typeid(Base) == typeid(Composed)) {
    std::cout << "BaseとComposedは同じクラスです" << std::endl;
  } else {
    std::cout << "BaseとComposedは異なるクラスです" << std::endl;
  }
}
