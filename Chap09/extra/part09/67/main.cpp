#include <array>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
struct FixedArray {
  std::array<T, N> data;
  std::size_t size() const { return N; }
  T& operator[](std::size_t i) { return data[i]; }
  const T& operator[](std::size_t i) const { return data[i]; }
};

int main() {
  FixedArray<int, 8> farr = {1, 2, 3, 4, 5, 6, 7, 8};

  std::cout << farr.size() << "\n";
}
