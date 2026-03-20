#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  std::ofstream out;
  out.open("hello_file.txt");

  out << "Hello, file IO" << std::endl;
  out << std::setprecision(4) << std::scientific << 12.34567f << std::endl;

  out.close();

  std::ifstream in{"hello_file.txt"};

  std::string line;
  std::getline(in, line);
  float f;
  in >> f;

  std::cout << line << std::endl;
  std::cout << f << std::endl;
}
