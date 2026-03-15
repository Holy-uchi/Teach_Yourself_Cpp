#include <iostream>

int main() {
  int i = 42;
  (void)i;

  if (int i = 0; i > 0) {
    std::cout << "if: " << i << std::endl;
  } else {
    std::cout << "else: " << i << std::endl;
  }
}
