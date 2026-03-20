#include <iostream>

int main() {
  char buffer[256];
  std::cin.getline(buffer, 256);

  std::cout << "buffer: " << buffer << std::endl;

  std::cin.get(buffer, 256, ',');

  std::cout << "buffer: " << buffer << std::endl;

  std::cin.get(buffer, 256, ',');

  if (buffer[0] == '\0') {
    std::cout << "バッファーは空" << std::endl;
  }
}
