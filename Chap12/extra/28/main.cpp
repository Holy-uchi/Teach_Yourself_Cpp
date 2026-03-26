#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {10, 20, 30, 40, 50};
  nums.erase(nums.begin());

  auto old_it = nums.begin();
  int& old_ref = nums[2];

  static_cast<void>(old_it);
  static_cast<void>(old_ref);

  auto it = nums.begin() + 2;
  int& ref = nums[2];

  std::cout << *it << '\n';
  std::cout << ref << '\n';
}
