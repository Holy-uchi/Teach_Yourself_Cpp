#include <iostream>

template <typename T>
class A {
public:
  void hello(T input) { std::cout << "Hello, " << input << std::endl; }
};

int main() {
  A<int> a1;
  a1.hello(3);

  A<std::string> a2;
  a2.hello("hoge");
}
