#include <iostream>

template <auto N>
struct ConstValue {
  static constexpr auto value = N;
};

int main() {
  std::cout << ConstValue<10>::value << "\n";
  std::cout << ConstValue<'a'>::value << "\n";
}
