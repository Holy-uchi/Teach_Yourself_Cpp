#include <iostream>
#include <string>

template <typename T>
  requires requires(T x, T y) { x + y; }
T add(T a, T b) {
  return a + b;
}

int main() {
  std::cout << add(1, 3) << "\n";

  std::string str1 = "Hello, ", str2 = "world!";
  std::cout << add(str1, str2) << "\n";

  // const char* cstr1 = "Hello, ";
  // const char* cstr2 = "world!";
  // add(cstr1, cstr2);
}
