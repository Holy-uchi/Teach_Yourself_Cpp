#include <type_traits>

template <typename T>
class vector2d {
  static_assert(std::is_signed<T>::value);
  T x;
  T y;

public:
};

int main() {
  vector2d<float> vf;
  vector2d<int> vi;
  // vector2d<unsigned int> vu;

  static_cast<void>(vf);
  static_cast<void>(vi);
}
