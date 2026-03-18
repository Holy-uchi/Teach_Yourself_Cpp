#include <iostream>
class Float {
  float value;

public:
  Float(float value) : value(value) {}

  Float(const Float& other) : value(other.value) {
    std::cout << "コピーコンストラクタ" << std::endl;
  }

  Float& operator=(const Float& other) {
    std::cout << "コピー代入" << std::endl;
    this->value = other.value;
    return *this;
  }

  friend Float operator+(Float lhs, const Float& rhs);
  friend Float operator-(Float lhs, const Float& rhs);
  friend Float operator*(Float lhs, const Float& rhs);
  friend Float operator/(Float lhs, const Float& rhs);

  float show() { return value; }
};

Float operator+(Float lhs, const Float& rhs) {
  lhs.value += rhs.value;
  return lhs;
}
Float operator-(Float lhs, const Float& rhs) {
  lhs.value -= rhs.value;
  return lhs;
}
Float operator*(Float lhs, const Float& rhs) {
  lhs.value *= rhs.value;
  return lhs;
}
Float operator/(Float lhs, const Float& rhs) {
  lhs.value /= rhs.value;
  return lhs;
}

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
