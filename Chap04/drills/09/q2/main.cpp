#include <iostream>

void hello() { std::cout << "Hello!" << std::endl; }
void goodbye() { std::cout << "Goodby!" << std::endl; }

int main() {
  hello();

#define hello goodbye
  hello();
#undef hello
}
