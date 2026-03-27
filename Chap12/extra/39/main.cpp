#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> scores = {
      {"alice", 80}, {"bob", 90}, {"carol", 85}};

  auto it = scores.find("bob");
  if (it != scores.end()) {
    std::cout << it->first << " : " << it->second << "\n";
  } else {
    std::cout << "not found" << "\n";
  }

  auto bob_exists = scores.contains("bob");
  std::cout << std::boolalpha << "bob exists? : " << bob_exists << "\n";

  auto bob_count = scores.count("bob");
  std::cout << "bob exists? : " << bob_count << "\n";
}
