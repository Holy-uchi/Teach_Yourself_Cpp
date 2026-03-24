#include <iostream>
#include <iterator>
#include <list>

int main() {
  std::list<int> lst = {100, 200, 300, 400, 500};

  auto third = std::next(lst.cbegin(), 2);
  std::cout << *third << std::endl;

  auto last = std::prev(lst.cend());
  std::cout << *last << std::endl;

  auto distance = std::distance(lst.cbegin(), last);
  std::cout << "distance=" << distance << std::endl;
  //
}
