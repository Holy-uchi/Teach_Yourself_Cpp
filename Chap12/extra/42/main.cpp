#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> scores = {
      {"alice", 80}, {"bob", 90}, {"carol", 85}};

  std::cout << "pairを取り出す" << "\n";
  for (const auto& el : scores) {
    std::cout << el.first << " : " << el.second << "\n";
  }

  std::cout << "構造化束縛" << "\n";
  for (const auto& [key, value] : scores) {
    std::cout << key << " : " << value << "\n";
  }
}
