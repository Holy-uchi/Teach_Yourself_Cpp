#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> iv = {6, 9, 7, 3, 2, 10, 1, 5, 8, 4};
  std::vector<int> iv2;

  std::copy(iv.begin(), iv.end(), std::back_inserter(iv2));
  std::sort(iv2.begin(), iv2.end(), [](int a, int b) { return a > b; });

  for (const auto& i : iv2) {
    std::cout << i << std::endl;
  }
}
