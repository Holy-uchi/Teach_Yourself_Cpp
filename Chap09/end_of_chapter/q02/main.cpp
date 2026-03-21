#include <iostream>

template <typename A, typename B, typename C>
class Object {
public:
  A a;
  B b;
  C c;

  void show() {
    std::cout << "(a, b, c) = " << "(" << this->a << ", " << this->b << ", "
              << this->c << ")" << std::endl;
  }
};

template <typename A, typename C>
class Object<A, void, C> {
public:
  A a;
  C c;

  void show() {
    std::cout << "(a, b, c) = " << "(" << this->a << ", " << this->c << ")"
              << std::endl;
  }
};

int main() {
  Object obj3{1, 1.234f, "hello"};
  obj3.show();

  Object<int, void, double> obj2{1, 3.14159265};
  obj2.show();
}
