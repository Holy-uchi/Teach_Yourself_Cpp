
#include <iostream>
#include <string>

int main() {
  std::string string = {'H', 'e', 'l', 'l', 'o', '\0', ',',
                        ' ', 'w', 'o', 'r', 'l', 'd'};
  std::cout << string << std::endl;
}
