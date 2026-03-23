#include <ios>
#include <iostream>
#include <string>

int main() {
  std::string str1{"abc"};
  std::string str2{"abd"};

  std::cout << std::boolalpha << (str1 < str2) << std::endl;
}
