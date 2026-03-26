#include <algorithm>
#include <iostream>
#include <vector>

struct Record {
  std::string name;
  int group;
};

int main() {
  std::vector<Record> records = {
      {"alice", 2}, {"bob", 1}, {"carol", 2}, {"dave", 1}, {"eve", 2}};

  std::stable_sort(records.begin(), records.end(),
                   [](auto a, auto b) { return a.group < b.group; });

  for (auto record : records) {
    std::cout << record.name << " : " << record.group << "\n";
  }
}
