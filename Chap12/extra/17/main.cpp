#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums1 = {1, 2, 3, 2, 4, 2};
  std::vector<int> nums2 = {5, 12, 8, 20, 7, 25};

  std::replace(nums1.begin(), nums1.end(), 2, 99);
  std::for_each(nums1.cbegin(), nums1.cend(),
                [](int a) { std::cout << a << std::endl; });

  std::replace_if(nums2.begin(), nums2.end(), [](int a) { return a > 10; }, 0);
  std::for_each(nums2.cbegin(), nums2.cend(),
                [](int a) { std::cout << a << std::endl; });
}
