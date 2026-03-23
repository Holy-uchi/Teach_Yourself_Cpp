#include <iostream>
#include <regex>
#include <string>

int main() {
  std::string str = "Hello World";

  std::regex re{"Hello"};

  std::string output = std::regex_replace(str, re, "Hi,");

  std::cout << output << std::endl;
}
