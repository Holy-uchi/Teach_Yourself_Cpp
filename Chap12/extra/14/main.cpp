#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  std::vector<int> doubled;

  std::transform(nums.cbegin(), nums.cend(), std::back_inserter(doubled),
                 [](int num) { return num * 2; });

  std::for_each(doubled.cbegin(), doubled.cend(),
                [](int num) { std::cout << num << std::endl; });
}
