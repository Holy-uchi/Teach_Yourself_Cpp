#include <cstddef>
#include <iostream>
#include <regex>
#include <string>

int main() {
  std::string str;
  std::string regex_str;

  std::cout << "文字列>> ";
  std::getline(std::cin, str);
  std::cout << "正規表現>> ";
  std::cin >> regex_str;

  std::regex re{regex_str};
  std::smatch match;

  if (std::regex_search(str, match, re)) {
    for (std::size_t i = 0; i < match.size(); ++i) {
      std::cout << i << ": [" << match.str(i) << "]" << std::endl;
    }
  }
}
