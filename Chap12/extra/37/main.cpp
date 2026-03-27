#include <iostream>
#include <map>
#include <utility>

int main() {
  std::map<std::string, int> scores;
  //
  scores.insert({"alice", 80});
  scores.insert(std::make_pair("bob", 90));

  for (const auto& [key, value] : scores) {
    std::cout << key << " : " << value << "\n";
  }

  scores.clear();

  scores.emplace("carol", 85);
  scores.emplace("dave", 88);

  for (const auto& [key, value] : scores) {
    std::cout << key << " : " << value << "\n";
  }
}
