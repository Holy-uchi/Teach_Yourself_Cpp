#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> a(5);
  std::vector<int> b(5);

  std::fill(a.begin(), a.end(), 7);
  std::for_each(a.cbegin(), a.cend(),
                [](int a) { std::cout << a << std::endl; });

  int num = 1;
  std::generate(b.begin(), b.end(), [&num]() { return num++; });
  std::for_each(b.cbegin(), b.cend(),
                [](int a) { std::cout << a << std::endl; });
}
