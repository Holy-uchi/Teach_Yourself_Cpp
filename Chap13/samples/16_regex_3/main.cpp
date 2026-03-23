#include <cstddef>
#include <iostream>
#include <regex>
#include <string>

int main() {
  std::regex re{"(A.*)C(.*A)"};
  std::string input = "ABRACADABRA";
  std::smatch match;

  if (std::regex_match(input, match, re)) {
    for (std::size_t i = 0; i < match.size(); ++i) {
      std::cout << match.str(i) << " position = " << match.position(i)
                << " length = " << match.length(i) << std::endl;
    }
  }
}
