// constメンバー関数からstaticメンバー変数を変更できることを示せ
#include <iostream>

class A {
public:
  static int value;
  void set_value(int new_value) const;
};

void A::set_value(int new_value) const { value = new_value; }

int A::value = 3;

int main() {
  std::cout << A::value << std::endl;
  const A ca;
  ca.set_value(5);
  std::cout << A::value << std::endl;
}
