#include <iostream>

class BaseA {
  int value;

public:
  BaseA(int value) : value{value} {
    std::cout << "BaseA::BaseA()" << std::endl;
  }
  void show_valueA() {
    std::cout << "BaseA.value=" << this->value << std::endl;
  }
};

class BaseB {
  int value;

public:
  BaseB(int value) : value{value} {
    std::cout << "BaseB::BaseB()" << std::endl;
  }
  void show_valueB() {
    std::cout << "BaseB.value=" << this->value << std::endl;
  }
};

class Derived : public BaseA, public BaseB {
public:
  Derived(int value_a, int value_b) : BaseA(value_a), BaseB(value_b) {
    std::cout << "Derived::Derived()" << std::endl;
  }
};

int main() {
  Derived derived{1, 42};
  BaseA& base_a = derived;
  base_a.show_valueA();

  BaseB& base_b = derived;
  base_b.show_valueB();
}
