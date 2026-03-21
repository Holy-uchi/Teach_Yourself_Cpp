#include <iostream>

template <typename T>
class A {
public:
  T value;
};

template <>
class A<void> {
public:
  std::string value = "void";
};

int main() {
  A<int> a{1};
  A<void> b;

  std::cout << a.value << std::endl;
  std::cout << b.value << std::endl;
}
