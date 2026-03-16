#include <iostream>
class A {
  int value = 0;

public:
  A() { std::cout << "コンストラクタ呼び出し" << std::endl; }
  ~A() { std::cout << "デストラクタ呼び出し" << std::endl; }
  int get_value() { return value; }
};

int main() {
  A* a = new A{};
  std::cout << a->get_value() << std::endl;
  delete a;
}
