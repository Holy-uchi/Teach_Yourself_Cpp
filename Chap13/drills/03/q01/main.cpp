#include <iostream>
#include <string>

int main() {
  std::string str1{"Hello, World!"};
  std::string str2 = str1.substr(7);

  std::cout << str2 << std::endl;
}
