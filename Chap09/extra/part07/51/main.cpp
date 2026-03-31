// XXX:

#include <iostream>
#include <utility>

struct A {
  void foo() { std::cout << "foo" << "\n"; }
};

struct B {};

template <typename T, typename = decltype(std::declval<T>().foo())>
void func(T x) {
  x.foo();
}

int main() {
  A a;
  func(a);

  // B b;
  // func(b);
}
