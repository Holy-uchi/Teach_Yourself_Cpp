#include <iostream>
#include <sys/syslimits.h>

class Base {
protected:
  void protected_member() {
    std::cout << "Base::protected_member()" << std::endl;
  }
};

class Derived : public Base {
public:
  void member_test();
};

void Derived::member_test() { protected_member(); }

int main() {
  Derived derived;

  derived.member_test();
}
