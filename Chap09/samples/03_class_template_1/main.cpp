#include <iostream>

template <typename T>
class vector2d {
public:
  T x;
  T y;
};

void show(int v) { std::cout << "int: " << v << std::endl; }
void show(float v) { std::cout << "float: " << v << std::endl; }

int main() {
  vector2d<float> f2d{10.0f, 20.0f};

  vector2d<int> i2d{10, 20};

  f2d.x = -10.0f;

  show(i2d.y);
  show(f2d.y);
}
