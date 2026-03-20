#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::string filename;
  std::getline(std::cin, filename);

  std::ifstream in{filename};

  std::string line;

  std::getline(in, line);
  std::cout << line << std::endl;
}
