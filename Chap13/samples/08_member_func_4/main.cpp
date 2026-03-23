#include <iostream>
#include <string>

int main() {
  std::string str = "C,C++,Java,Ruby,";
  std::string delim = ",";

  std::string::size_type fpos = 0;
  while ((fpos = str.find_first_not_of(delim, fpos)) != std::string::npos) {
    auto lpos = str.find_first_of(delim, fpos);

    std::string token(str, fpos, lpos - fpos);
    std::cout << "[" << token << "] ";
    fpos = lpos;
  }
  std::cout << std::endl;
}
