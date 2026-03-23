#include <iostream>
#include <regex>
#include <string>

int main() {
  std::regex re{R"(A\w*A)"};
  std::string input = "ABRACADABRA";

  if (std::regex_match(input, re)) {
    std::cout << "マッチしました！" << std::endl;
  }
}
