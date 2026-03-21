#include <iostream>

class Base {
public:
  virtual void foo(int i) { std::cout << "Base::foo()" << i << std::endl; }
};

template <typename T>
class Derived : public Base {
public:
  void foo(T val) override {
    std::cout << "Derived::foo(): " << val << std::endl;
  }
};

int main() {
  Derived<int> di;
  static_cast<Base&>(di).foo(0);

  // Derived<float> fi;
}
