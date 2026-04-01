#include <cstddef>
#include <iostream>

template <size_t N>
constexpr size_t length(const char (&)[N]) {
  return N;
}

int main() { std::cout << length("hello") << std::endl; }
