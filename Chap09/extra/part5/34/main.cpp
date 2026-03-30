#include <iostream>

template <typename T>
struct TypeName {
  static void print() { std::cout << "value\n"; }
};

template <typename T>
struct TypeName<T*> {
  static void print() { std::cout << "pointer\n"; }
};

int main() { TypeName<int*>::print(); }
