#include <iostream>
#include <memory>

void printValue(const int* p) {
  if (p) {
    std::cout << "value: " << *p << '\n';
  }
}

int main() {
  auto iptr = std::make_unique<int>(42);

  printValue(iptr.get());

  if (iptr) {
    std::cout << "iptr still owns pointer\n";
    std::cout << *iptr << "\n";
  }
}
