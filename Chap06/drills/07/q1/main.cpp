#include <iostream>
#include <memory>

class A {
  int value;

public:
  explicit A(int value) : value(value) {}
  void show() const { std::cout << value << std::endl; }
};

int main() {
  std::unique_ptr<A> ptr = std::make_unique<A>(3);
  ptr->show();

  // std::unique_ptr<A> ptr2 = ptr; コピーするとエラー
  std::unique_ptr<A> ptr2 = std::move(ptr);
  ptr2->show();
}
