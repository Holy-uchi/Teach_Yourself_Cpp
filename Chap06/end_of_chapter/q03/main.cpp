#include <iostream>

class Integer {
  int value;

public:
  Integer(int value) : value(value) {}

  friend Integer operator+(Integer lhs, const Integer& rhs);
  friend Integer operator-(Integer lhs, const Integer& rhs);
  friend Integer operator*(Integer lhs, const Integer& rhs);
  friend Integer operator/(Integer lhs, const Integer& rhs);
  void show() const { std::cout << this->value << std::endl; }
};

Integer operator+(Integer lhs, const Integer& rhs) {
  lhs.value += rhs.value;
  return lhs;
}
Integer operator-(Integer lhs, const Integer& rhs) {
  lhs.value -= rhs.value;
  return lhs;
}
Integer operator*(Integer lhs, const Integer& rhs) {
  lhs.value *= rhs.value;
  return lhs;
}
Integer operator/(Integer lhs, const Integer& rhs) {
  lhs.value /= rhs.value;
  return lhs;
}

int main() {
  Integer a = 3;
  Integer b = 4;
  auto c = a + b;
  c.show();
}
