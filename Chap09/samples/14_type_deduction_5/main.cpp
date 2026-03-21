#include <iostream>

template <typename T>
struct A {
  T value;
};

template <typename T>
T get_value(A<T> a) {
  return a.value;
}

int main() {
  A<int> ai{42};

  std::cout << get_value(ai) << std::endl;

  A<double> ad{3.1415};

  std::cout << get_value(ad) << std::endl;
}
