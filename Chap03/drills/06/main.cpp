#include <iostream>

class A {
  int value{0};

public:
  void set_value(int value, bool use_this = true);
  int get_value() const;
};

void A::set_value(int value, bool use_this) {
  if (use_this) {
    this->value = value;
  } else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wself-assign"
    value = value; // わざと
#pragma clang diagnostic pop
  }
}
int A::get_value() const { return this->value; }

int main() {
  A a;
  a.set_value(1);
  std::cout << a.get_value() << std::endl;
  a.set_value(2, false);
  std::cout << a.get_value() << std::endl;
}
