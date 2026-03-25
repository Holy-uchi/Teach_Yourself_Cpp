#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> nums = {3, 6, 9, 12, 15, 18};
  std::vector<int> copied;
  std::vector<int> evens;

  std::copy(nums.cbegin(), nums.cend(), std::back_inserter(copied));
  std::for_each(copied.cbegin(), copied.cend(),
                [](int a) { std::cout << a << std::endl; });

  std::copy_if(nums.cbegin(), nums.cend(), std::back_inserter(evens),
               [](int a) { return a % 2 == 0; });
  std::for_each(evens.cbegin(), evens.cend(),
                [](int a) { std::cout << a << std::endl; });
}
