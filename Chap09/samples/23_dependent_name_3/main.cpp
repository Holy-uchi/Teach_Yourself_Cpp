#include <vector>

template <typename T>
using vector_reference = typename std::vector<T>::reference;

template <typename T>
vector_reference<T> at(std::vector<T>& v, std::size_t i) {
  return v[i];
}

int main() {
  std::vector<int> v = {0, 1, 2, 3};

  auto r = at(v, 0);
  static_cast<void>(r);
}
