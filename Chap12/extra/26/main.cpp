#include <iostream>
#include <map>
#include <set>

int main() {
  std::map<std::string, int> scores = {
      {"alice", 80}, {"bob", 65}, {"carol", 90}};
  std::set<int> nums = {10, 20, 30, 40, 50};

  scores.erase("bob");

  std::cout << "scores: " << "\n";
  for (const auto& [key, value] : scores) {
    std::cout << key << " : " << value << "\n";
  }

  nums.erase(30);
  std::cout << "nums: " << "\n";
  for (auto num : nums) {
    std::cout << num << "\n";
  }
}
