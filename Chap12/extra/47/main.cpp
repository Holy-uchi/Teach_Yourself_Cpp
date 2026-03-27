#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<std::string> words = {"cat", "dog", "bird"};
  std::vector<std::size_t> lengths;

  std::transform(words.cbegin(), words.cend(), std::back_inserter(lengths),
                 [](const auto& word) { return word.size(); });

  for (auto len : lengths) {
    std::cout << len << "\n";
  }
}
