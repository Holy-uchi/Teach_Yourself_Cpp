#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> scores = {{"alice", 80}, {"bob", 90}};

  std::cout << scores["alice"] << "\n";

  std::cout << "初期状態\n";
  std::cout << "size = " << scores.size() << "\n";
  std::cout << "alice = " << scores["alice"] << "\n\n";

  std::cout << "operator[]でcarolを取得する前\n";
  std::cout << "size = " << scores.size() << "\n";
  std::cout << "carol exists? " << (scores.count("carol") ? "yes" : "no")
            << "\n";

  std::cout << "scores[\"carol\"] = " << scores["carol"] << "\n";

  // 例外
  // scores.at("carol");
}
