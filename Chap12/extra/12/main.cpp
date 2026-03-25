#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

int main() {
  std::cout.setf(std::ios::boolalpha);
  std::vector<int> nums = {2, 4, 6, 8, 10};

  auto is_all_even =
      std::all_of(nums.cbegin(), nums.cend(), [](int a) { return a % 2 == 0; });
  std::cout << "全要素が偶数であるか: " << is_all_even << std::endl;

  auto any_gt_10 =
      std::any_of(nums.cbegin(), nums.cend(), [](int a) { return a > 10; });
  std::cout << "1つでも10より大きい要素があるか: " << any_gt_10 << std::endl;

  auto no_odd_nums = std::none_of(nums.cbegin(), nums.cend(),
                                  [](int a) { return a % 2 != 0; });
  std::cout << "奇数が1つも存在しないか: " << no_odd_nums << std::endl;
}
