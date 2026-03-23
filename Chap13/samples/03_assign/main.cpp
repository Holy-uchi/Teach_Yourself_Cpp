#include <iostream>
#include <string>

int main() {
  std::string s0;

  s0.assign("Hello");
  std::cout << "s0: " << s0 << std::endl;

  s0.assign("Hello", 4);
  std::cout << "s0: " << s0 << std::endl;

  std::string s1 = "Hello";
  s0.assign(s1);
  std::cout << "s0: " << s0 << std::endl;

  s0.assign(3, '?');
  std::cout << "s0: " << s0 << std::endl;

  s0.assign({'a', 'b', 'c'});
  std::cout << "s0: " << s0 << std::endl;

  s0.assign(s1.begin() + 1, s1.end() - 1);
  std::cout << "s0: " << s0 << std::endl;

  s0.assign(s1, 1, 3);
  std::cout << "s0: " << s0 << std::endl;
}
