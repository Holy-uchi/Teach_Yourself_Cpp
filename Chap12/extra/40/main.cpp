#include <iostream>
#include <set>
#include <vector>

int main() {
  std::vector<int> nums = {3, 1, 2, 3, 2, 4, 1, 5};
  std::set<int> nums_set{nums.begin(), nums.end()};

  for (auto num : nums_set) {
    std::cout << num << "\n";
  }

  std::cout << "numsの要素数: " << nums.size() << "\n";
  std::cout << "nums_setの要素数: " << nums_set.size() << "\n";
}
