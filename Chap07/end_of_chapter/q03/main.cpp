#include <iostream>

class Base {
  int value;

public:
  Base(int value) : value{value} {
    std::cout << "Base::Base(" << value << ")" << std::endl;
  }
  void show_value() { std::cout << this->value << std::endl; }
};

class DerivedA : virtual public Base {
public:
  DerivedA() : Base(1) {}
};

class DerivedB : virtual public Base {
public:
  DerivedB() : Base(2) {}
};

class MoreDerived : public DerivedA, public DerivedB {
public:
  MoreDerived() : Base{3} {
    std::cout << "MoreDerived::MoreDerived()" << std::endl;
  }
};

int main() {
  MoreDerived more_derived;
  more_derived.show_value();
}
