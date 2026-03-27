#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  std::vector<std::string> words = {"a", "bb", "ccc"};

  auto acc = std::accumulate(nums.cbegin(), nums.cend(), 0);
  std::cout << acc << "\n";

  auto total_char =
      std::accumulate(words.cbegin(), words.cend(), 0,
                      [](auto a, const auto& b) { return a + b.size(); });
  std::cout << total_char << "\n";
}
