#include <iostream>

int main() {
  char buffer[256];

  do {
    std::cout << ">>> ";
    std::cin.getline(buffer, 256);
    std::cout << "buffer: " << buffer << std::endl;
  } while (buffer[0] != '\0');
}
