#include <iostream>

class A {
  int m_v;

public:
  explicit A(int v) : m_v(v) {}

  int v() const { return m_v; }
};

int main() {
  A x{0};
  A y(42);
  std::cout << (y.v() == 42) << std::endl;
}
