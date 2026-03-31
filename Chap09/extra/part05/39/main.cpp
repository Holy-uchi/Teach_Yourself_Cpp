#include <iostream>
template <typename T>
struct IsPointer {
  static constexpr bool value = false;
};

template <typename T>
struct IsPointer<T*> {
  static constexpr bool value = true;
};

int main() {
  std::cout << IsPointer<int*>::value << "\n";
  std::cout << IsPointer<double*>::value << "\n";
  std::cout << IsPointer<int>::value << "\n";
}
