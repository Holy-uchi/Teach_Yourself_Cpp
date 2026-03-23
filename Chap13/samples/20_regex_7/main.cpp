#include <iostream>
#include <iterator>
#include <regex>
#include <string>

int main() {
  std::regex re{"(.)もも"};

  std::string input = "すもももももももものうち";
  std::string fmt = "$1うどん";
  std::string output;

  std::regex_replace(std::back_inserter(output), input.begin(), input.end(), re,
                     fmt);

  std::cout << output << std::endl;
}
