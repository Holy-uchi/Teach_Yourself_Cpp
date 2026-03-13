#include <iostream>

class Vector3d {
  float x;
  float y;
  float z;

public:
  Vector3d();
  explicit Vector3d(float x, float y, float z);

  friend Vector3d add(const Vector3d& lhs, const Vector3d& rhs);
  friend Vector3d sub(const Vector3d& lhs, const Vector3d& rhs);

  void dump() const;
};

Vector3d::Vector3d() : Vector3d(0, 0, 0) {}

Vector3d::Vector3d(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3d add(const Vector3d& lhs, const Vector3d& rhs) {
  Vector3d result;
  result.x = lhs.x + rhs.x;
  result.y = lhs.y + rhs.y;
  result.z = lhs.z + rhs.z;
  return result;
}
Vector3d sub(const Vector3d& lhs, const Vector3d& rhs) {
  Vector3d result;
  result.x = lhs.x - rhs.x;
  result.y = lhs.y - rhs.y;
  result.z = lhs.z - rhs.z;
  return result;
}

void Vector3d::dump() const {
  std::cout << x << ", " << y << ", " << z << std::endl;
}

int main() {
  Vector3d a(1, 1, 1), b(1, 2, 3);
  Vector3d c = add(a, b);
  c.dump();
  Vector3d d = sub(a, b);
  d.dump();
}
