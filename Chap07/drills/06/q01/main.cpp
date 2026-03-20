#include <iostream>

class Base {
public:
  Base(int value) { std::cout << "Base::Base(" << value << ")" << std::endl; }
};

class DerivedA : virtual public Base {
public:
  DerivedA(int value) : Base{value} {
    std::cout << "DerivedA::DerivedA(" << value << ")" << std::endl;
  }
};

class DerivedB : virtual public Base {
public:
  DerivedB(int value) : Base{value} {
    std::cout << "DerivedB::DerivedB(" << value << ")" << std::endl;
  }
};

class MoreDerived : public DerivedA, public DerivedB {
public:
  MoreDerived() : Base{3}, DerivedA(1), DerivedB(2) {
    std::cout << "MoreDerived::MoreDerived()" << std::endl;
  }
};

int main() { MoreDerived more_derived; }
