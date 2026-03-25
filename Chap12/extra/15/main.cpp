#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {10, 20, 30, 40};

  std::transform(nums.begin(), nums.end(), nums.begin(),
                 [](int a) { return a - 5; });

  std::for_each(nums.cbegin(), nums.cend(),
                [](int a) { std::cout << a << std::endl; });
}
