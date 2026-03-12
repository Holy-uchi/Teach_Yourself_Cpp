#include <cstddef>
#include <iostream>

int main() {
  char string[] = {'H', 'e', 'l', 'l', 'o', '\0'};

  for (std::size_t i = 0; i < sizeof(string) / sizeof(string[0]); i++) {
    std::cout << string[i] << std::endl;
  }
}
