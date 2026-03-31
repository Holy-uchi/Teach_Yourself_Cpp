#include <iostream>

template <bool IsFast>
struct Algorithm {};

template <>
struct Algorithm<true> {
  static constexpr const char* value = "fast";
};

template <>
struct Algorithm<false> {
  static constexpr const char* value = "safe";
};

int main() {
  std::cout << Algorithm<true>::value << std::endl;
  std::cout << Algorithm<false>::value << std::endl;
}
