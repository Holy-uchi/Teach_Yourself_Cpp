#include <cstddef>
#include <iostream>
#include <vector>

template <typename T>
using vector_reference = std::vector<T>::reference;

template <typename T>
vector_reference<T> at(std::vector<T>& v, std::size_t i) {
  return v[i];
}

int main() {
  std::vector<int> v{1, 2, 3, 4, 5};
  std::cout << at(v, 3) << std::endl;
}
