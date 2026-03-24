#include <iostream>
#include <string>

int main() {
  auto str1 = std::string{"Hello, "};
  auto str2 = std::string{"World!"};

  auto str3 = str1 + str2;

  std::cout << str3 << std::endl;
}
