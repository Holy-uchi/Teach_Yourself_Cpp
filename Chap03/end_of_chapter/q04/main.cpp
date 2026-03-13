// フレンド関数はクラスのプライベートメンバーにアクセスできることを示せ
#include <iostream>

class A {
  int value = 0;

public:
  A(int value) : value(value) {}
  friend void print_value(const A& a);
};

void print_value(const A& a) { std::cout << a.value << std::endl; }

int main() {
  A a{5};
  print_value(a);
}
