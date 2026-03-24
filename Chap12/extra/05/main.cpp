#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {5, 10, 15, 20, 25, 30};

  auto first = v.begin() + 1;
  auto last = v.begin() + 4;

  for (auto it = first; it != last; ++it) {
    *it *= 2;
  }

  for (const auto& el : v) {
    std::cout << el << std::endl;
  }
}
