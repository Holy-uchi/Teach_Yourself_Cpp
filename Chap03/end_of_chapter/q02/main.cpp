#include <iostream>
class vector3d {
  float x = 0;
  float y = 0;
  float z = 0;

public:
  vector3d() = default;
  vector3d(float x, float y);
  vector3d(float x, float y, float z);
  void dump() const;
};

vector3d::vector3d(float x, float y) : x(x), y(y) {}
vector3d::vector3d(float x, float y, float z) : x(x), y(y), z(z) {}
void vector3d::dump() const {
  std::cout << this->x << ", " << this->y << ", " << this->z << std::endl;
}

int main() {
  vector3d v1;
  vector3d v2{1, 2};
  vector3d v3{1, 2, 3};

  v1.dump();
  v2.dump();
  v3.dump();
}
