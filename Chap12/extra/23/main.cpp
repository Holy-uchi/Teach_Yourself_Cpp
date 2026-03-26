#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {2, 5, 8, 11, 14, 17, 20};

  for (auto it = nums.begin(); it != nums.end();) {
    if (*it > 10) {
      it = nums.erase(it);
    } else {
      ++it;
    }
  }

  std::for_each(nums.cbegin(), nums.cend(),
                [](int a) { std::cout << a << '\n'; });
}
