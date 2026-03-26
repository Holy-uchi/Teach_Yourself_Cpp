#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {3, 8, 15, 22, 7, 14, 19, 28};

  auto is_even = [](int a) { return a % 2 == 0; };

  auto first_even = std::find_if(nums.cbegin(), nums.cend(), is_even);
  if (first_even != nums.cend()) {
    std::cout << "最初の偶数: " << *first_even << "\n";
  } else {
    std::cout << "最初の偶数: 無し\n";
  }

  auto count_even = std::count_if(nums.cbegin(), nums.cend(), is_even);
  std::cout << "偶数の個数: " << count_even << "\n";

  nums.erase(std::remove_if(nums.begin(), nums.end(), is_even), nums.end());
  std::cout << "nums: {";
  for (std::size_t i = 0; i < nums.size(); ++i) {
    std::cout << nums[i];
    if (i + 1 < nums.size()) {
      std::cout << ", ";
    }
  }
  std::cout << "}" << std::endl;
}
