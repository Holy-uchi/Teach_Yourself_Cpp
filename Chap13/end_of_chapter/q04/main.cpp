#include <iostream>
#include <regex>
#include <string>

int main() {
  std::string str{"Hello, World!"};
  std::regex re{"Hello"};
  std::string fmt{"Hi"};

  auto str2 = std::regex_replace(str, re, fmt);
  std::cout << str2 << std::endl;
}
