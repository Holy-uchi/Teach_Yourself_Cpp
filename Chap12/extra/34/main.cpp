#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

int main() {
  std::cout << std::boolalpha;
  std::vector<int> a = {1, 2, 3, 4, 5};
  std::vector<int> b = {1, 3, 2, 4, 5};

  auto a_sorted = std::is_sorted(a.cbegin(), a.cend(),
                                 [](auto a, auto b) { return a < b; });

  std::cout << "a_sorted: " << a_sorted << "\n";

  auto b_sorted = std::is_sorted(b.cbegin(), b.cend(),
                                 [](auto a, auto b) { return a < b; });

  std::cout << "b_sorted: " << b_sorted << "\n";

  auto a_sorted_desc = std::is_sorted(a.cbegin(), a.cend(),
                                      [](auto a, auto b) { return a > b; });

  std::cout << "a_sorted_desc: " << a_sorted_desc << "\n";
}
