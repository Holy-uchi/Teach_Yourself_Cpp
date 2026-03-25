#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {5, 7, 9, 12, 15, 18};

  const auto even = std::find_if(nums.cbegin(), nums.cend(),
                                 [](int num) { return num % 2 == 0; });

  if (even != nums.cend()) {
    std::cout << *even << std::endl;
  } else {
    std::cout << "not found" << std::endl;
  }
}
