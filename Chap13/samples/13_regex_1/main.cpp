#include <iostream>
#include <regex>
#include <string>

int main() {
  std::regex re{"a.*e"};
  std::string input = "delicious applepie and banana";
  std::smatch match;

  if (std::regex_search(input, match, re)) {
    std::cout << match.str() << " pos = " << match.position()
              << " len = " << match.length() << std::endl;
  }
}
