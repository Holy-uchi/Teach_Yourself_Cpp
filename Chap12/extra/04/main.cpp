#include <iostream>
#include <vector>

void print_all(const std::vector<std::string>& words) {
  for (auto word : words) {
    std::cout << word << std::endl;
  }
}

int main() {
  std::vector<std::string> words = {"aa", "bb", "cc"};

  // 問１
  for (auto word : words) {
    word.append("!");
  }
  print_all(words);

  // 問２
  words = {"aa", "bb", "cc"};

  for (auto& word : words) {
    word.append("!");
  }
  print_all(words);

  // 問３
  words = {"aa", "bb", "cc"};

  for (const auto& word : words) {
    // word.append("!"); // コンパイルエラー
    static_cast<void>(word);
  }
  print_all(words);
}
