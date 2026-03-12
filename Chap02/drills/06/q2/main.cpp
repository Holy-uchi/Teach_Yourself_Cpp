#include <iostream>
#include <string>

int main() {
  std::string str;
  std::cout << "一行入力してください>> ";
  std::getline(std::cin, str);

  std::cout << str << std::endl;
}
