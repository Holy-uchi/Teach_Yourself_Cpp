#include <initializer_list>
#include <iostream>

class A {
  int value;

public:
  A(std::initializer_list<int> ini) : value(0) {
    for (auto& el : ini) {
      std::cout << el << std::endl;
    }
  }

  int get_value() { return this->value; }
};

int main() { A a{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; }
