#include <iostream>
#include <vector>

int main() {
  std::vector<int> iv = {1, 2, 3, 4, 5};

  for (const int& i : iv) {
    std::cout << i << std::endl;
  }
  iv.erase(iv.begin() + 2);
  for (const int& i : iv) {
    std::cout << i << std::endl;
  }
}
