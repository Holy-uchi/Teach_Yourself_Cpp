#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {4, 7, 10, 13, 16, 19, 22};

  auto it = std::remove_if(nums.begin(), nums.end(),
                           [](int a) { return a % 2 != 0; });
  nums.erase(it, nums.end());

  std::for_each(nums.cbegin(), nums.cend(),
                [](int a) { std::cout << a << '\n'; });
}
