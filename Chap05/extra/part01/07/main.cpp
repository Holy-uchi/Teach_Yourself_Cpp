#include <cstddef>
#include <iostream>
#include <memory>

int main() {
  auto iptr = std::make_unique<int>(42);
  auto iarr_ptr = std::make_unique<int[]>(3);

  std::cout << *iptr << "\n";

  for (std::size_t i = 0; i < 3; ++i) {
    iarr_ptr[i] = (i + 1) * 10;
  }

  for (std::size_t i = 0; i < 3; ++i) {
    std::cout << iarr_ptr[i] << "\n";
  }
}
