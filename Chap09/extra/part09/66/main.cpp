#include <iostream>

template <typename Derived>
class Base {
public:
  void interface() { static_cast<Derived*>(this)->impl(); }
};

class Derived : public Base<Derived> {
public:
  void impl() { std::cout << "inpl\n"; }
};

int main() {
  Derived d;

  d.interface();
}
