#include <iostream>

class S {
public:
  template <typename T>
  void foo(T value) {
    std::cout << "foo: " << value << std::endl;
  }

  template <typename T>
  void bar(T value);
};

template <typename T>
void S::bar(T value) {
  std::cout << "bar: " << value << std::endl;
}

int main() {
  S s;

  s.foo<int>(0);

  s.bar<float>(0.0f);
}
