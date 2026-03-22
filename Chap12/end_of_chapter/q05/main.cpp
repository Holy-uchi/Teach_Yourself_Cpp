#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> iv = {5, 6, 5, 7, 4, 0, 4};

  const int count = std::count(iv.begin() + 1, iv.end(), *iv.begin());

  std::cout << count << std::endl;
}
