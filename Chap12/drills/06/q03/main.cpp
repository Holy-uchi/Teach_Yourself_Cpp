#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> iv = {6, 9, 7, 3, 2, 10, 1, 5, 8, 4};
  std::vector<int> iv2 = {
      0,
  };

  std::copy(iv.begin(), iv.end(), std::inserter(iv2, iv2.begin()));

  for (const auto& i : iv2) {
    std::cout << i << std::endl;
  }
}
