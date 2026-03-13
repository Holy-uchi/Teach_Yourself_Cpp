#include <iostream>

class A {
  static int count;

public:
  static void show_count();
  A();
};

int A::count = 0;

A::A() { count++; }

void A::show_count() { std::cout << A::count << std::endl; }

int main() {
  A a1;
  A::show_count();
  A a2;
  A a3;
  A::show_count();
}
