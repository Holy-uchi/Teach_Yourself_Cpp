#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

int main() {
  std::vector<int> nums = {7, 3, 5, 3, 9, 1, 7, 2};
  //
  std::set<int> nums_set{nums.cbegin(), nums.cend()};
  std::unordered_set<int> nums_uset{nums.cbegin(), nums.cend()};

  std::cout << "nums_set:\n";
  for (auto num : nums_set) {
    std::cout << num << "\n";
  }

  std::cout << "nums_uset:\n";
  for (auto num : nums_uset) {
    std::cout << num << "\n";
  }
}
