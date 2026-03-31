#include <cstddef>
#include <iostream>
template <typename T>
struct IsArray {
  static constexpr bool value = false;
};

template <typename T, std::size_t N>
struct IsArray<T[N]> {
  static constexpr bool value = true;
};

int main() { std::cout << IsArray<int[3]>::value << std::endl; }
