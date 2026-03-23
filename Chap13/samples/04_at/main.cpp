#include <iostream>
#include <stdexcept>
#include <string>

int main() {
  std::string str = "123";
  for (std::string::size_type i = 0; i < str.length(); ++i) {
    std::cout << str[i];
  }
  std::cout << std::endl;

  char ch = 'a';
  for (std::string::size_type i = 0; i < 10; ++i) {
    try {
      str.at(i) = ch++;
    } catch (std::out_of_range& err) {
      std::cerr << "Oops..." << err.what() << std::endl;
      break;
    }
  }
  std::cout << str << std::endl;
}
