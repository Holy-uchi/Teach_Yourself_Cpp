#include <cstddef>
#include <vector>

template <typename T>
typename std::vector<T>::reference at(std::vector<T>& v, std::size_t i) {
  return v[i];
}

template <typename T>
// size_tは依存名じゃないのでtypenameは要らないが、別にエラーにはならない。
typename std::size_t size(const std::vector<T>& v) {
  return v.size();
}

int main() {
  std::vector<int> v = {0, 1, 2, 3};

  std::vector<int>::reference r = at(v, 0);
  static_cast<void>(r);
}
