#include <iostream>

class vector3d {
public:
  using value_type = int;
  value_type get_x();
  value_type get_y();
  value_type get_z();

  void set_x(value_type new_x);
  void set_y(value_type new_y);
  void set_z(value_type new_z);

private:
  value_type x;
  value_type y;
  value_type z;
};

vector3d::value_type vector3d::get_x() { return x; }
vector3d::value_type vector3d::get_y() { return y; }
vector3d::value_type vector3d::get_z() { return z; }

void vector3d::set_x(vector3d::value_type new_x) { x = new_x; }
void vector3d::set_y(vector3d::value_type new_y) { y = new_y; }
void vector3d::set_z(vector3d::value_type new_z) { z = new_z; }

vector3d set(vector3d::value_type a, vector3d::value_type b,
             vector3d::value_type c = 0) {
  vector3d vec;
  vec.set_x(a);
  vec.set_y(b);
  vec.set_z(c);

  return vec;
}

void show_vector(vector3d vec) {
  std::cout << "[" << vec.get_x() << ", " << vec.get_y() << ", " << vec.get_z()
            << "]" << std::endl;
}

int main() {
  vector3d v;
  v.set_x(1);
  v.set_y(2);
  v.set_z(3);

  show_vector(v);

  v = set(4, 5);
  show_vector(v);
}
