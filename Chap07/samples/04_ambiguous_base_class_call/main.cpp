#include <iostream>

class Base {
  int value;

public:
  Base(int value) : value(value) {};
  void show_value() { std::cout << this->value << std::endl; }
};

class DerivedA : public Base {
public:
  DerivedA(int value) : Base{value} {}
};

class DerivedB : public Base {
public:
  DerivedB(int value) : Base{value} {}
};

class MoreDerived : public DerivedA, public DerivedB {
public:
  MoreDerived(int value_a, int value_b)
      : DerivedA(value_a), DerivedB(value_b) {}
};

int main() {
  MoreDerived more_derived{1, 42};
  more_derived.DerivedA::show_value();
  more_derived.DerivedB::show_value();
  Base& base_a = static_cast<DerivedA&>(more_derived);
  base_a.show_value();
  Base& base_b = static_cast<DerivedB&>(more_derived);
  base_b.show_value();
}
