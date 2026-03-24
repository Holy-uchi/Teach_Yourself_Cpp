#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {10, 20, 30, 40, 50, 60, 70};

  auto first = v.begin() + 2;
  auto last = v.begin() + 5;

  for (auto it = first; it != last; ++it) {
    std::cout << *it << std::endl;
  }
}
