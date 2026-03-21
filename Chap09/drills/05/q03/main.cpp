#include <iostream>

template <typename T>
struct A {
  T value;
};

template <typename T>
void show_value(A<T> a) {
  std::cout << "value=" << a.value << std::endl;
}

int main() {
  A<double> a{3.14159265};
  show_value(a);
}
