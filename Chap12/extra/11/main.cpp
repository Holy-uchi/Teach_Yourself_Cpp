#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {1, 2, 2, 3, 4, 2, 5, 6};

  auto num_two = std::count(nums.cbegin(), nums.cend(), 2);
  std::cout << "2の個数: " << num_two << std::endl;

  auto num_even = std::count_if(nums.cbegin(), nums.cend(),
                                [](int a) { return a % 2 == 0; });
  std::cout << "偶数の個数: " << num_even << std::endl;
}
