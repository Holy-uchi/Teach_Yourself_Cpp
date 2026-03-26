#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums1 = {8, 1, 6, 3, 9, 2};
  std::vector<int> nums2 = {8, 1, 6, 3, 9, 2};

  std::cout << "nums1:" << "\n";
  std::sort(nums1.begin(), nums1.end(), [](auto a, auto b) { return a < b; });
  for (auto num : nums1) {
    std::cout << num << "\n";
  }

  std::cout << "nums2:" << "\n";
  std::sort(nums2.begin(), nums2.end(), [](auto a, auto b) { return a > b; });
  for (auto num : nums2) {
    std::cout << num << "\n";
  }
}
