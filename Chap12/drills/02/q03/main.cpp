#include <iostream>
#include <vector>

int main() {
  std::vector<int> iv{1, 2, 3, 4, 5};

  for (const auto& i : iv) {
    std::cout << i << std::endl;
  }

  iv.push_back(6);
  for (const auto& i : iv) {
    std::cout << i << std::endl;
  }
}
