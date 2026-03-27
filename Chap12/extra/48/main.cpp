#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> nums = {5, 12, 7, 20, 3, 18, 9, 24};
  std::vector<int> selected;

  std::copy_if(nums.cbegin(), nums.cend(), std::back_inserter(selected),
               [](int a) { return a >= 10; });

  for (auto num : selected) {
    std::cout << num << "\n";
  }
}
