#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {4, 2, 7, 2, 4, 1, 7, 3, 1, 5};

  std::sort(nums.begin(), nums.end());
  auto it = std::unique(nums.begin(), nums.end());
  nums.erase(it, nums.end());

  for (auto num : nums) {
    std::cout << num << "\n";
  }
}
