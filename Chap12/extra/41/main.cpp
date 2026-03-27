#include <iostream>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, int> scores = {
      {"alice", 80}, {"bob", 90}, {"carol", 85}};

  for (const auto& score : scores) {
    std::cout << score.first << " : " << score.second << "\n";
  }
}
