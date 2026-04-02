#include <iostream>
#include <memory>

void legacyProcess(int* p) {
  if (p) {
    *p += 10;
  }
}

int main() {
  auto i_ptr = std::make_unique<int>(10);

  legacyProcess(i_ptr.get());

  if (i_ptr) {
    std::cout << *i_ptr << std::endl;
  }
}
