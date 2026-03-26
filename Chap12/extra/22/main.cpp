#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {1, 1, 2, 2, 2, 3, 3, 4, 4, 5};
  auto it = std::unique(nums.begin(), nums.end());
  nums.erase(it, nums.end());

  std::cout << "nums:\n";
  std::for_each(nums.cbegin(), nums.cend(),
                [](int a) { std::cout << a << '\n'; });

  std::cout << "====\n";

  std::vector<int> nums2 = {3, 1, 3, 2, 2, 1, 1};
  it = std::unique(nums2.begin(), nums2.end());
  nums2.erase(it, nums2.end());

  std::cout << "nums2:\n";
  std::for_each(nums2.cbegin(), nums2.cend(),
                [](int a) { std::cout << a << '\n'; });
}
