#include <iostream>
#include <vector>

int main() {

  std::vector<int> nums = {1, 2, 3, 4, 5};

  for (auto it = nums.crbegin(); it != nums.crend(); ++it) {
    std::cout << *it << std::endl;
  }
}
