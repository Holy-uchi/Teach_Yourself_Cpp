#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> scores = {{"alice", 80}, {"bob", 90}};
  //
  auto it = scores.find("alice");
  if (it != scores.end()) {
    it->second = 85;
  }

  it = scores.find("carol");
  if (it != scores.end()) {
    it->second = 100;
  }

  for (const auto& [key, value] : scores) {
    std::cout << key << " : " << value << "\n";
  }
}
