#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> words = {"red", "green", "blue"};

  for (auto it = words.cbegin(); it != words.cend(); ++it) {
    std::cout << *it << std::endl;
  }
}
