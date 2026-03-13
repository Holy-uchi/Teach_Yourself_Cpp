#include <iostream>

class A {
  int v;

public:
  void set(int value);
  const int& get() const;
  int& get();
};

void A::set(int value) { v = value; }
const int& A::get() const {
  std::cout << "const参照を返すメソッドが呼ばれました" << std::endl;
  return v;
}
int& A::get() {
  std::cout << "参照を返すメソッドが呼ばれました" << std::endl;
  return v;
}

int main() {
  A a;
  a.set(42);
  std::cout << a.get() << std::endl;

  const A& ca = a;
  std::cout << ca.get() << std::endl;
}
