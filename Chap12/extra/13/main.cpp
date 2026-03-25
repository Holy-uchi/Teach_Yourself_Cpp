#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> words = {"cat", "dog", "bird"};

  std::for_each(words.cbegin(), words.cend(),
                [](const std::string& str) { std::cout << str << std::endl; });
}
