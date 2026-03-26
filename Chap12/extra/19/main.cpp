#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> nums = {1, 2, 3, 2, 4, 2, 5};

  auto it = std::remove(nums.begin(), nums.end(), 2);
  std::for_each(nums.cbegin(), nums.cend(),
                [](int a) { std::cout << a << '\n'; });

  std::cout << "====" << std::endl;

  std::cout << "removeの戻り値が指す位置: " << std::distance(nums.begin(), it)
            << std::endl;
}
