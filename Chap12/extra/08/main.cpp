#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> v = {11, 22, 33, 44};
  //
  auto first = v.cbegin();
  std::cout << *first << std::endl;

  auto end_it = v.cend();        // これは終端。要素を指さない。
  auto last = std::prev(end_it); // 1つ戻して末尾要素を指す。
  std::cout << *last << std::endl;
}
