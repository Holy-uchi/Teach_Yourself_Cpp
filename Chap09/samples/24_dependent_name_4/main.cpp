#include <iostream>

template <typename T>
class A {
public:
  A() {}

  template <typename U>
  A(A<U>) {}

  template <typename U>
  using rebind = A<U>;

  template <typename U>
  void foo() {
    std::cout << "A<T>::foo<U>()" << std::endl;
  }

  template <typename U>
  void bar(U u) {
    std::cout << "A<T>::bar<U>(" << u << ")" << std::endl;
  }
};

template <typename U, typename T>
void call_foo(A<T>& a) {
  typename A<T>::template rebind<U> b = a;

  b.template foo<int>();

  b.bar(42);
}

int main() {
  A<int> a;

  call_foo<void>(a);
}
