#include <iostream>
#include <regex>
#include <string>

int main() {
  std::regex re{"([^A]+A)([^A]+A)"};
  std::string input = "ABRACADABRA";
  std::smatch match;

  if (std::regex_search(input, match, re)) {
    for (std::size_t i = 0; i < match.size(); ++i) {
      std::cout << "[" << match.str(i) << "]"
                << " position = " << match.position(i)
                << " length = " << match.length(i) << std::endl;
    }
  }
}
