#include <iostream>
class Float {
  float value;

public:
  Float(float value) : value(value) {}

  Float operator+(const Float& rhs) const { return Float{value + rhs.value}; }
  Float operator-(const Float& rhs) const { return Float{value - rhs.value}; }
  Float operator*(const Float& rhs) const { return Float{value * rhs.value}; }
  Float operator/(const Float& rhs) const { return Float{value / rhs.value}; }
  Float operator+() const { return *this; }
  Float operator-() const { return Float{-value}; }

  void show() const { std::cout << "Float.value = " << value << std::endl; }
};

int main() {
  Float a = 1.5f;
  Float b = 2.8f;

  auto c = a + b;
  c.show();
  c = a - b;
  c.show();
  c = a * b;
  c.show();
  c = a / b;
  c.show();
  c = +a;
  c.show();
  c = -a;
  c.show();
}
