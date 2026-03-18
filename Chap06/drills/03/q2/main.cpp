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

  Float& operator++() {
    this->value += 1;
    return *this;
  }
  Float operator++(int) {
    Float tmp{this->value};
    ++*this;
    return tmp;
  }
  Float& operator--() {
    this->value -= 1;
    return *this;
  }
  Float operator--(int) {
    Float tmp{this->value};
    --*this;
    return tmp;
  }

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
  c = a + b;
  (c++).show();
  (++c).show();
  (c--).show();
  (--c).show();
}
