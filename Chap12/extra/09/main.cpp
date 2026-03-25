#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {8, 3, 15, 6, 10};

  const auto iter = std::find(nums.cbegin(), nums.cend(), 15);

  if (iter != nums.cend()) {
    std::cout << *iter << std::endl;
  } else {
    std::cout << "not found" << std::endl;
  }
}
