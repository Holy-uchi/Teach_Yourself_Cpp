#include <iostream>

class Base {
public:
  Base() { std::cout << "Baseコンストラクタ" << std::endl; }
  ~Base() { std::cout << "Baseデストラクタ" << std::endl; }
};

class Derived : public Base {
public:
  Derived() { std::cout << "Derivedコンストラクタ" << std::endl; }
  ~Derived() { std::cout << "Derivedデストラクタ" << std::endl; }
};

int main() {
  Derived derived;
  std::cout << "derivedオブジェクト構築" << std::endl;
}
