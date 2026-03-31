// XXX:

#include <iostream>
#include <type_traits>
#include <utility>

struct A {
  void foo() { std::cout << "foo\n"; }
};

struct B {};

template <typename T, typename = void>
struct has_foo : std::false_type {};

template <typename T>
struct has_foo<T, std::void_t<decltype(std::declval<T>().foo())>>
    : std::true_type {};

template <typename T>
inline constexpr bool dependent_false = false;

template <typename T, std::enable_if_t<has_foo<T>::value, int> = 0>
void f(T x) {
  x.foo();
}

template <typename T, std::enable_if_t<!has_foo<T>::value, int> = 0>
void f(T) {
  static_assert(dependent_false<T>, "T should have a foo() member function.");
}

int main() {
  A a;
  f(a);

  // B b;
  // f(b);
}
