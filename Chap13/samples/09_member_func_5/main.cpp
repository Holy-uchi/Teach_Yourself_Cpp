#include <iostream>
#include <string>

int main() {
  std::string s0 = "ushi";
  s0 += "mo";
  std::cout << "s0: " << s0 << std::endl;

  std::string s1 = "shika";
  s0.append(s1);
  std::cout << "s0: " << s0 << std::endl;

  s0.insert(4, "ka");
  std::cout << "s0: " << s0 << std::endl;

  s0.erase(0, 4);
  std::cout << "s0: " << s0 << std::endl;

  s0.replace(4, 5, "me");
  std::cout << "s0: " << s0 << std::endl;
}
