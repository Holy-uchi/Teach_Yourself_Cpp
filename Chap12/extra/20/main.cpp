#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {1, 2, 3, 2, 4, 2, 5};

  auto it = std::remove(nums.begin(), nums.end(), 2);
  nums.erase(it, nums.end());

  std::for_each(nums.cbegin(), nums.cend(),
                [](int a) { std::cout << a << '\n'; });

  std::cout << "numsの要素数: " << nums.size() << std::endl;
}
