#include <cstddef>
#include <iostream>

void reverse(int* arr, std::size_t len) {
  for (std::size_t i = 0; i < len / 2; i++) {
    int tmp = arr[i];
    arr[i] = arr[len - 1 - i];
    arr[len - 1 - i] = tmp;
  }
}

int main() {
  int array[] = {0, 1, 2, 3, 4};
  reverse(array, 5);

  std::cout << array[0] << std::endl;
  std::cout << array[1] << std::endl;
  std::cout << array[2] << std::endl;
  std::cout << array[3] << std::endl;
  std::cout << array[4] << std::endl;
}
