#include <ios>
#include <iostream>

template <typename T>
T id(T in) {
  return in;
}

int main() {
  std::cout << "int: " << id<int>(5) << std::endl;
  std::cout << "float: " << id<int>(5) << std::endl;
  std::cout << "double: " << id<int>(5) << std::endl;
  std::cout << std::boolalpha << "bool: " << id<bool>(true) << std::endl;
}
