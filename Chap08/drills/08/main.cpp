#include <fstream>
#include <iostream>

int main() {
  std::ifstream in{"in_file.txt", std::ios::in};
  in.seekg(0, std::ios::end);

  auto state = in.rdstate();
  std::cout << "state: " << state << std::endl;

  in.get();

  state = in.rdstate();
  std::cout << "state: " << state << std::endl;
}
