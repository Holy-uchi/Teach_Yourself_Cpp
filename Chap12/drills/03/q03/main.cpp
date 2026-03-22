#include <iostream>
#include <list>

int main() {
  std::list<int> il = {4, 1, 5, 2, 3};
  for (const auto& i : il) {
    std::cout << i << std::endl;
  }
  il.sort();
  for (const auto& i : il) {
    std::cout << i << std::endl;
  }
}
