#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums1 = {5, 2, 7, 4, 9, 6, 1, 8};
  std::vector<int> nums2 = {5, 2, 7, 4, 9, 6, 1, 8};

  std::partition(nums1.begin(), nums1.end(), [](int a) { return a % 2 == 0; });
  std::cout << "nums1 (partition):" << "\n";
  for (auto num : nums1) {
    std::cout << num << "\n";
  }

  std::stable_partition(nums2.begin(), nums2.end(),
                        [](int a) { return a % 2 == 0; });
  std::cout << "nums2 (stable_partition):" << "\n";
  for (auto num : nums2) {
    std::cout << num << "\n";
  }
}
