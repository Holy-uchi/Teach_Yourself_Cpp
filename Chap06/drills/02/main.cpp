#include <iostream>
class Float {
  float value;

public:
  Float(float value) : value(value) {}

  Float operator+(const Float& rhs) { return Float{value + rhs.value}; }
  Float operator-(const Float& rhs) { return Float{value - rhs.value}; }
  Float operator*(const Float& rhs) { return Float{value * rhs.value}; }
  Float operator/(const Float& rhs) { return Float{value / rhs.value}; }

  float show() { return value; }
};

int main() {
  Float a = 1.5f;
  Float b = 2.8f;

  auto c = a + b;
  std::cout << c.show() << std::endl;
  c = a - b;
  std::cout << c.show() << std::endl;
  c = a * b;
  std::cout << c.show() << std::endl;
  c = a / b;
  std::cout << c.show() << std::endl;
}
