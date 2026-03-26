#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {10, 20, 30, 40, 50};
  std::deque<int> d = {10, 20, 30, 40, 50};

  auto v_el_erase = v.begin() + 2;
  v.erase(v_el_erase);

  std::cout << "v: \n";
  std::for_each(v.cbegin(), v.cend(), [](int a) { std::cout << a << '\n'; });

  auto d_el_erase = d.begin() + 2;
  d.erase(d_el_erase);

  std::cout << "d: \n";
  std::for_each(d.cbegin(), d.cend(), [](int a) { std::cout << a << '\n'; });
}
