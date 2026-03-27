#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> a = {8, 3, 15, 6, 10};
  std::vector<int> b = {8, 3, 15, 6, 10};
  std::vector<int> c = {8, 3, 15, 6, 11};

  auto min_a = std::min_element(a.cbegin(), a.cend());
  std::cout << *min_a << "\n";

  auto max_a = std::max_element(a.cbegin(), a.cend());
  std::cout << *max_a << "\n";

  auto a_eq_b = std::equal(a.cbegin(), a.cend(), b.cbegin());
  std::cout << std::boolalpha << a_eq_b << "\n";

  auto a_eq_c = std::equal(a.cbegin(), a.cend(), c.cbegin());
  std::cout << std::boolalpha << a_eq_c << "\n";
}
