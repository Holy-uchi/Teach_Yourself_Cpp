#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {42, 7, 19, 3, 25, 10};

  std::cout << "ソート前の要素数: " << nums.size() << "\n";

  std::sort(nums.begin(), nums.end());

  std::cout << "ソート後の要素数: " << nums.size() << "\n";

  for (auto num : nums) {
    std::cout << num << "\n";
  }
}
