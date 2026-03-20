#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ofstream out;

  out.open("hello_file.txt", std::ios::trunc);

  out << "Hello, file IO" << std::endl;

  out.close();

  std::ifstream in{"hello_file.txt", std::ios::in};

  std::string line;
  std::getline(in, line);

  std::cout << line << std::endl;
}
