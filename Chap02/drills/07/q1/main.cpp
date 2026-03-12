#include <iostream>

void show_value(int a) { std::cout << a << std::endl; }

int sum(int a, int b, int c, int d) { return a + b + c + d; }

int sum(int a, int b, int c) { return sum(a, b, c, 0); }

int sum(int a, int b) { return sum(a, b, 0, 0); }

int main() {
  int x = sum(10, 20);
  show_value(x);

  int y = sum(5, 15, 25);
  show_value(y);

  int z = sum(1, 2, 3, 4);
  show_value(z);
}
