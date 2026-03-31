#include <iostream>

template <typename T>
struct Printer {
  static void print() { std::cout << "general\n"; }
};

template <>
struct Printer<int> {
  static void print() { std::cout << "int specialized\n"; }
};

int main() { Printer<int>::print(); }
