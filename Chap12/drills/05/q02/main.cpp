#include <iostream>
#include <set>

int main() {
  std::set<int> is = {1, 2, 3, 4, 5};

  for (const auto& i : is) {
    std::cout << i << std::endl;
  }

  is.insert(3);
  for (const auto& i : is) {
    std::cout << i << std::endl;
  }
}
