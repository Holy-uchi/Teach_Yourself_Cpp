#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream in{"Chap08/drills/05/q02/main.cpp"};
  std::string line;

  do {
    std::getline(in, line);
    std::cout << line << std::endl;
  } while (!in.eof());
}
