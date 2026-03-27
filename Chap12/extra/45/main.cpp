#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main() {
  std::vector<int> src = {10, 20, 30};
  std::vector<int> dst1;
  std::set<int> dst2;
  std::set<int> dst3;

  std::copy(src.cbegin(), src.cend(), std::back_inserter(dst1));
  std::copy(src.cbegin(), src.cend(), std::inserter(dst2, dst2.begin()));
  dst3.insert(src.cbegin(), src.cend());

  std::cout << "dst1:" << "\n";
  for (auto num : dst1) {
    std::cout << num << "\n";
  }
  std::cout << "\n";

  std::cout << "dst2:" << "\n";
  for (auto num : dst2) {
    std::cout << num << "\n";
  }
  std::cout << "\n";

  std::cout << "dst3:" << "\n";
  for (auto num : dst3) {
    std::cout << num << "\n";
  }
  std::cout << "\n";
}
