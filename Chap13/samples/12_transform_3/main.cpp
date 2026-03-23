#include <charconv>
#include <iostream>

int main() {
  char buffer[16] = {};

  auto result = std::to_chars(buffer, buffer + 15, 10);
  *result.ptr = '\0';
  std::cout << buffer << std::endl;

  int val = 0;
  std::from_chars(buffer, buffer + 16, val);
  std::cout << val << std::endl;

  result = std::to_chars(buffer, buffer + 15, 0xdeadbeef, 16);
  *result.ptr = '\0';
  std::cout << buffer << std::endl;

  std::from_chars(buffer, buffer + 16, val, 16);
  std::cout << val << std::endl;

  result =
      std::to_chars(buffer, buffer + 15, 3.14, std::chars_format::scientific);
  *result.ptr = '\0';
  std::cout << buffer << std::endl;

  // double fval = 0;
  // std::from_chars(buffer, buffer + 16, fval);
  // std::cout << val << std::endl;
}
