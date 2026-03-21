#include <iostream>

template <typename A, typename B, typename C>
struct Tuple {
  A a;
  B b;
  C c;

  void show() const {
    std::cout << '{' << a << ", " << b << ", " << c << '}' << std::endl;
  }
};

template <typename A, typename C>

struct Tuple<A, void, C> {
  A a;
  C c;

  void show() const { std::cout << '{' << a << ", " << c << '}' << std::endl; }
};

int main() {
  Tuple<int, void, float> t = {42, 3.1415};
  t.show();
}
