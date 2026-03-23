#include <iostream>
#include <string>

int main() {
  std::string str = "abc";

  const char* c_str = str.c_str();

  int pos = 0;
  while (true) {
    if (c_str[pos] == '\0') {
      std::cout << "[\\0]" << std::endl;
      break;
    } else {
      std::cout << c_str[pos] << std::endl;
    }
    pos++;
  }
}
