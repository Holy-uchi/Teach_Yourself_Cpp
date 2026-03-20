#include <fstream>
#include <iostream>

int main() {
  std::ofstream out{"tmp.txt"};
  out << "Hello, world";

  out.seekp(7);
  out << "file seek";
}
