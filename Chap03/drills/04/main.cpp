#include <iostream>

class Vector3d {
  float x{0};
  float y{0};
  float z{0};

public:
  void print() const;
};

void Vector3d::print() const {
  std::cout << "x: " << this->x << ", y: " << this->y << ", z:" << this->z
            << std::endl;
}

int main(void) {
  Vector3d vec;
  vec.print();
}
