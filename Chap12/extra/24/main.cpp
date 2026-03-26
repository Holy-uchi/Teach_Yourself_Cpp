#include <algorithm>
#include <iostream>

int main() {
  std::string s = "a b  c   d e";

  auto it = std::remove(s.begin(), s.end(), ' ');
  s.erase(it, s.end());

  std::cout << s << std::endl;
}
