#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ofstream out{"hello_eof.txt"};

  out << "Hello, EOF";

  out.close();

  std::ifstream in{"hello_eof.txt"};

  std::string line;
  std::getline(in, line);

  std::cout << line << std::endl;
  std::cout << "ファイル末尾? " << std::boolalpha << in.eof() << std::endl;
}
