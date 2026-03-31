#include <iostream>

template <typename T>
struct Category {
  static constexpr const char* name = "value";
};

template <typename T>
struct Category<T*> {
  static constexpr const char* name = "pointer";
};

template <typename T>
struct Category<const T> {
  static constexpr const char* name = "const value";
};

template <typename T>
struct Category<T&> {
  static constexpr const char* name = "reference";
};

int main() {
  std::cout << Category<int>::name << "\n";
  std::cout << Category<int*>::name << "\n";
  std::cout << Category<const int>::name << "\n";
  std::cout << Category<int&>::name << "\n";
}
