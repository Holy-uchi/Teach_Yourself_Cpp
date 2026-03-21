#include <iostream>
#include <string>

template <typename T>
class helper;

template <>
class helper<int> {
public:
  static std::string name() { return "int"; }
};

template <>
class helper<double> {
public:
  static std::string name() { return "double"; }
};

template <typename T>
struct A {
  T value;
};

template <typename T>
void deduce(A<T> a) {
  (void)a;
  std::cout << helper<T>::name() << std::endl;
}

int main() {
  A<int> ai{42};

  deduce(ai);

  A<double> ad{3.1415};

  deduce(ad);
}
