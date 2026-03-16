#include <cstddef>
#include <iostream>

int* allocate(std::size_t size) {
  int* iarr = new int[size];
  for (std::size_t i = 0; i < size; i++) {
    iarr[i] = 0;
  }
  return iarr;
}

int main() {
  int* arr5 = allocate(5);
  for (size_t i = 0; i < 5; i++) {
    std::cout << arr5[i] << std::endl;
  }
}
