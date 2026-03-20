#include <iostream>

class Base {
public:
  Base() { std::cout << "Baseコンストラクタ" << std::endl; }
  Base(int i) { std::cout << "Base引数付きコンストラクタ: " << i << std::endl; }
  ~Base() { std::cout << "Baseデストラクタ" << std::endl; }
};

class Derived : public Base {
public:
  explicit Derived(int i) : Base{i} {
    std::cout << "Derivedコンストラクタ" << std::endl;
  }
  ~Derived() { std::cout << "Derivedデストラクタ" << std::endl; }
};

int main() {
  Derived derived{42};
  std::cout << "derivedオブジェクト構築" << std::endl;
}
