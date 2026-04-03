#include <cstdlib>
#include <iostream>

struct Point {
  int x;
  int y;

  Point(int a, int b) : x(a), y(b) {
    std::cout << "construct: " << x << ", " << y << '\n';
  }

  ~Point() { std::cout << "destruct: " << x << ", " << y << '\n'; }
};

int main() {
  void* mem = std::malloc(sizeof(Point));

  // まだmemは触ってはいけない
  Point* p = new (mem) Point(3, 4);

  std::cout << "(" << p->x << ", " << p->y << ")\n";

  p->~Point();

  std::free(mem);
}
