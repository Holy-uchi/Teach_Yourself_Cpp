#include <iostream>
#include <regex>
#include <string>

int main() {
  std::string str;
  std::string re_str;

  std::cin >> str;
  std::cin >> re_str;

  std::regex re{re_str};

  std::smatch match;

  if (std::regex_match(str, match, re)) {
    std::cout << "match" << std::endl;
  } else {
    std::cout << "not match" << std::endl;
  }
}
