#include <iostream>
#include <list>

int main() {
  std::list<int> nums = {3, 6, 9, 12, 15, 18, 21};

  for (auto it = nums.begin(); it != nums.end();) {
    if (*it % 3 == 0 && *it > 10) {
      it = nums.erase(it);
    } else {
      ++it;
    }
  }

  for (auto num : nums) {
    std::cout << num << std::endl;
  }
}
